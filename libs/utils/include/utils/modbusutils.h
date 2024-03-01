#ifndef UTILSD__UTILS_H_
#define UTILSD__UTILS_H_

#include <cstdint>
#include <boost/asio/streambuf.hpp>

#include <iostream>


/**
 * Макрос для удобства обработки ошибок при чтении и записи по протоколу модбас через ModbusClient
 */
#define MODBUS_RW_ERROR_HANDLE(request_method, positive_instructions, negative_instructions, error_status) \
error_status = request_method; \
if (error_status == modbus::NO_MODBUS_ERROR) {positive_instructions} else { negative_instructions; }


/**
 * Пространство имен, содержащие основные функции и классы для взаимодействия танго девайса с физическим
 * устройством по протоколу Modbus RTU over TCP
 */
namespace modbus {

/**
 * Перечисление, характеризующее статус ответа клиенту по модбас
 */
enum ModbusResult {
  /**
   * Ошибок нет
   */
      NO_MODBUS_ERROR = 0,

  /**
   * Принятый код функции не может быть обработан.
   */
      ILLEGAL_FUNCTION = 1,

  /**
   * Адрес данных, указанный в запросе, недоступен.
   */
      ILLEGAL_DATA_ADDRESS = 2,

  /**
   * 	Значение, содержащееся в поле данных запроса, является недопустимой величиной.
   */
      ILLEGAL_DATA_VALUE = 3,

  /**
   * Невосстанавливаемая ошибка имела место, пока ведомое устройство
   * пыталось выполнить затребованное действие.
   */
      SERVER_DEVICE_FAILURE = 4,

  /**
   * Ведомое устройство приняло запрос и обрабатывает его, но это требует много времени.
   * Этот ответ предохраняет ведущее устройство от генерации ошибки тайм-аута.
   */
      ACKNOWLEDGE = 5,

  /**
   * 06	Ведомое устройство занято обработкой команды.
   * Ведущее устройство должно повторить сообщение позже, когда ведомое освободится.
   */
      SERVER_DEVICE_BUSY = 6,

  /**
   * Ведомое устройство не может выполнить программную функцию, заданную в запросе.
   * Этот код возвращается для неуспешного программного запроса,
   * использующего функции с номерами 13 или 14.
   * Ведущее устройство должно запросить диагностическую информацию
   * или информацию об ошибках от ведомого.
   */
      NEGATIVE_ACKNOWLEDGE = 7,

  /**
   * 	Ведомое устройство при чтении расширенной памяти обнаружило ошибку паритета.
   * 	Ведущее устройство может повторить запрос, но обычно в таких случаях требуется ремонт.
   */
      MEMORY_PARITY_ERROR = 8,

  /**
   * Шлюз неправильно настроен или перегружен запросами.
   */
      GATEWAY_PATH_UNAVAILABLE = 10,

  /**
   * Slave устройства нет в сети или от него нет ответа.
   */
      GATEWAY_TARGET_DEVICE_FAILED_TO_RESPOND = 11,

  //@section Далее идут ошибки, напрямую НЕ относяшиеся к modbus протоколу

  /**
   * Непонятная ошибка. Используется во всех тех случаях, под которые не подходит ни один
   * из пунктов данного перечисления
   */
      UNHANDLED_ERROR = 255,

  NO_SOCKET_CONNECTION = 254,

  /**
   * Ошибка таймаута, который вызван не обязательно самим мобдасом,
   * но может и самим соединением
   */
      TCP_TIMEOUT_ERROR = 253,

  /**
   * Ответ не является корректным с точки зрения модбас протокола
   */
      INVALID_RESPONSE = 252,

  /**
   * Запрос не является корректным, с точки зрения модбас протокола
   */
      INVALID_REQUEST = 251,

  /**
   * Ошибка контрольной суммы, которая обнаружена непосредственно на стороне клиента
   */
      CRC_ERROR = 250,
};

inline uint16_t getMask(uint8_t byte_num, uint8_t byte_count) {
  uint16_t mask_right = ((0xffff) << (byte_num + byte_count));
  uint16_t mask_left = ((0xffff) >> (15 - (byte_num - 1)));
  uint16_t mask = mask_left | mask_right;
  return mask;
}

inline uint16_t readByteValue(uint8_t byte_num, uint8_t byte_count, uint16_t value) {
  uint16_t mask = getMask(byte_num, byte_count) ^0xffff;
  uint16_t result = (value & mask) >> byte_num;

  return result;
}

inline bool writeByteValue(uint8_t byte_num, uint8_t byte_count, uint16_t value_to_write, uint16_t &value) {
  std::cout << "VALUE BEFORE: " << unsigned(value) << std::endl;
  uint16_t mask = getMask(byte_num, byte_count);
  uint16_t value_mask = (0xffff >> (15 - byte_count - 1));

//  if ((value_to_write & value_mask) != value_to_write) return false;

  std::cout << "VALUE TO WRITE BEFORE: " << unsigned(value_to_write) << std::endl;

  value_to_write = ((value_to_write & value_mask) << byte_num);

  std::cout << "VALUE TO WRITE AFTER: " << unsigned(value_to_write) << std::endl;
  value &= mask;
  value |= value_to_write;

  std::cout << "VALUE AFTER: " << unsigned(value) << std::endl;

  return true;
}

inline void toMsbLsb(uint16_t data, uint8_t &lsb, uint8_t &msb) {
  lsb = data >> 8;
  msb = data & 0x00FF;
}

inline void fromMsbLsb(uint8_t lsb, uint8_t msb, uint16_t &data) {
  data = lsb;
  data <<= 8;
  data = msb | data;
}

inline void toMsbLsb(uint32_t data, uint16_t &lsb, uint16_t &msb) {
  msb = data >> 16;
  lsb = data & 0xFFFF;
}

inline void fromMsbLsb(uint16_t lsb, uint16_t msb, uint32_t &data) {
  data = msb;
  data <<= 16;
  data = lsb | data;
}

inline void crcRTU(const uint8_t *buffer, uint16_t buffer_size, uint8_t &crc_msb, uint8_t &crc_lsb) {
  uint16_t pos;
  uint8_t i;
  uint16_t crc = 0xFFFF;

  for (pos = 0; pos < buffer_size; pos++) {
    crc ^= (uint16_t) buffer[pos];          // XOR byte into least sig. byte of crc

    for (uint8_t i = 8; i != 0; i--) {    // Loop over each bit
      if ((crc & 0x0001) != 0) {      // If the LSB is set
        crc >>= 1;                    // Shift right and XOR 0xA001
        crc ^= 0xA001;
      } else                            // Else LSB is not set
        crc >>= 1;                    // Just shift right
    }
  }

  crc_lsb = crc >> 8;
  crc_msb = crc & 0x00FF;
  // Note, this number has low and high bytes swapped, so use it accordingly (or swap bytes)
}

inline int make_stream_from_buffer(boost::asio::streambuf &asio_buffer, uint8_t *buff, size_t buff_size) {
  auto out = std::ostreambuf_iterator<char>(&asio_buffer);
  for (size_t i = 0; i < buff_size; i++)
    *out++ = buff[i];

  return buff_size;
}
}

#endif //UTILSD__UTILS_H_
