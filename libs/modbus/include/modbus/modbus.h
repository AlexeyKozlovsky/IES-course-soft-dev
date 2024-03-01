#ifndef DIALTEK_COMPONENTS_LIBMODBUS_MODBUS_H_
#define DIALTEK_COMPONENTS_LIBMODBUS_MODBUS_H_

#include <mutex>

#include <boost/asio.hpp>
#include <boost/beast/core/tcp_stream.hpp>

#include <utils/modbusutils.h>

#include "tcp_socket.h"


namespace modbus {

/**
 * Класс для осуществления работы с модбас устройством по протоколу Modbus RTU over TCP
 * Класс содержит только основные операции для использования, а т.е. чтение INPUT регистров
 * и чтение и запись HOLDING регистров.
 *
 * Так же, планируется предусмотреть обработку ошибок
 */
class ModbusClient {
  friend class ModbusClientTest;
 public:
  inline std::string getIP() const {
    return ip;
  };

  inline uint16_t getPort() const {
    return port;
  };

  /**
   * Присваивает IP. Не рекомендуется использовать вместе с setPort, если в обоих случаях to_update = true.
   * Будут происходить лишние обновления. В таком случае, если надо поменять и IP, и port, есть два варианта:
   *
   * Первый вариант:
   * \code
   *    setIP("192.168.0.90", false);
   *    setPort(4001, true);
   * \endcode
   *
   * Второй вариант:
   * \code
   *    setAddress("192.168.0.90", 4001);
   * \endcode
   * @param ip -- новый ip адрес
   * @param to_update -- указывает на то, следует ли обновить сокет после изменения
   * значения IP. Если true, то сокет обновляется, иначе -- нет.
   */
  inline void setIP(std::string ip, bool to_update = false) {
    this->ip = ip;
    if (to_update) update();
  };

  /**
   * Обновляет значение порта. Рекомендации к использованию аналогичны методу \code setIP(std::string, bool) \endcode
   *
   * @param port -- новое значение порта
   * @param to_update -- указывает на то, следует ли обновить сокет после изменения
   * значения порта. Если true, то сокет обновляется, иначе -- нет.
   */
  inline void setPort(uint16_t port, bool to_update = false) {
    this->port = port;
    if (to_update) update();
  };

  /**
   * Метод для изменения всего адреса
   * @param ip
   * @param port
   * @param to_update
   */
  inline void setAddress(std::string ip, uint16_t port, bool to_update = true) {
    this->ip = ip;
    this->port = port;
    if (to_update) update();
  };

  inline bool isConnected() {
    // КОСТЫЛЬ, потом поменять
    uint16_t value;
    return readInputRegister(0, value) == modbus::NO_MODBUS_ERROR;
  };

  ModbusClient();

  ModbusClient(std::string ip, uint16_t port);

  /**
   * Метод для установки соединения с физическим устройством
   * @return true, если соединение установлено, false -- иначе
   */
  bool connect();

  /**
   * Метод для разрыва соединеня с физическим устройством
   */
  void disconnect();

  /**
   * Метод для того, чтобы задать таймаут сокету
   * @param timeout -- время таймаута в милисекундах
   */
  void setTimeout(int timeout);

  /**
   * Метод для чтения одного Input регистра. Рекомендуется использовать его, когда
   * необходимо за раз читать только один регистр по той принчине, что не создается бесполнезного
   * вектора
   * @param reg_num -- номер начального регистра
   * @param reg_count -- количество регистров, которое надо прочитать
   * @param result -- набор 16-битных значений, которые были прочитаны из регистров
   * @return true, если все прошло без ошибок, иначе -- false
   */
  modbus::ModbusResult readInputRegister(uint16_t reg_num,
                                         uint16_t &result,
                                         uint8_t modbus_id = 1,
                                         uint8_t *raw_response = nullptr,
                                         uint8_t *raw_request = nullptr);

  /**
   * Метод для чтения Input регистров. Можно читать как один, так и несколько регистров
   * @param reg_num -- номер начального регистра
   * @param reg_count -- количество регистров, которое надо прочитать
   * @param result -- набор 16-битных значений, которые были прочитаны из регистров
   * @return true, если все прошло без ошибок, иначе -- false
   */
  modbus::ModbusResult readInputRegisters(uint16_t reg_num,
                                          uint16_t reg_count,
                                          std::vector<uint16_t> &result,
                                          uint8_t modbus_id = 1,
                                          uint8_t *raw_response = nullptr,
                                          uint8_t *raw_request = nullptr);

  /**
    * Метод для чтения Holding регистра. Рекомендуется использовать его, когда
    * необходимо за раз читать только один регистр по той принчине, что не создается бесполнезного
    * вектора.
    * @param reg_count -- количество регистров, которое надо прочитать
    * @param result -- набор 16-битных значений, которые были прочитаны из регистров
    * @return true, если все прошло без ошибок, иначе -- false
    */
  modbus::ModbusResult readHoldingRegister(uint16_t reg_num,
                                           uint16_t &result,
                                           uint8_t modbus_id = 1,
                                           uint8_t *raw_response = nullptr,
                                           uint8_t *raw_request = nullptr);

  /**
    * Метод для чтения Holding регистров. Можно читать как один, так и несколько регистров
    * @param reg_num -- номер начального регистра
    * @param reg_count -- количество регистров, которое надо прочитать
    * @param result -- набор 16-битных значений, которые были прочитаны из регистров
    * @return true, если все прошло без ошибок, иначе -- false
    */
  modbus::ModbusResult readHoldingRegisters(uint16_t reg_num,
                                            uint16_t reg_count,
                                            std::vector<uint16_t> &result,
                                            uint8_t modbus_id = 1,
                                            uint8_t *raw_response = nullptr,
                                            uint8_t *raw_request = nullptr);

  /**
   * Метод для записи значения в Holding регистр
   * @param reg_num -- номер регистра
   * @param value -- значение для записи
   * @return true, если все прошло без ошибок, иначе -- false
   */
  modbus::ModbusResult writeHoldingRegister(uint16_t reg_num,
                                            uint16_t value,
                                            uint8_t modbus_id = 1,
                                            uint8_t *raw_response = nullptr,
                                            uint8_t *raw_request = nullptr);

  /**
   * Метод, который пишет несколько регистров за один запрос
   * @param reg_num
   * @param values
   * @return
   */
  modbus::ModbusResult writeHoldingRegistersTrue(uint16_t reg_num,
                                                 std::vector<uint16_t> values,
                                                 uint8_t modbus_id = 1,
                                                 uint8_t *raw_response = nullptr,
                                                 uint8_t *raw_request = nullptr);

  /**
   * Метод для записи значенией в Holding регистры (последовательно). За несколько запросов
   * @param reg_num начальный номер регистра
   * @param values вектор значений (будут записаны последовательно в регистры под номерами начиная
   * с первого переданного
   * @return true если запись прошла успешно, false -- иначе
   */
  modbus::ModbusResult writeHoldingRegisters(uint16_t reg_num,
                                             std::vector<uint16_t> values,
                                             uint8_t modbus_id = 1,
                                             uint8_t *raw_response = nullptr,
                                             uint8_t *raw_request = nullptr);

 private:

  /**
   * IP адрес, который присваивается по умолчанию при создании клиента
   * с помощью конструктора без параметров
   */
  static const std::string default_ip;

  /**
   * Порт, который присваивается по умолчанию при создании клиента
   * с помощью конструктора без параметров
   */
  static const uint16_t default_port;

  int timeout;

  /**
   * IP адрес физического устройства
   */
  std::string ip;

  /**
   * Порт, на котором физическое устройство слушает MODBUS запросы
   */
  uint16_t port;

  /**
   * Содержит информацию об ошибках на транспортном уровне
   */
  boost::system::error_code ec;

  /**
   * Контекст для установления и поддержки соединения через boost
   */
  boost::asio::io_context context;
  boost::asio::io_service service;

  TcpConnection connection;

  /**
   * Эндпоинт для соединения, по которому находится физическое устройство
   */
  boost::asio::ip::tcp::endpoint endpoint;

  /**
   * Сокет для взаимодействия с физическим устройством
   */
  boost::beast::tcp_stream socket;

  /**
   * Мьютекст для того, чтобы не допускать нескольких чтений и записи одновременно
   */
  std::mutex comm_mutex;

  /**
   * Вспомогательный метод для отправки сырого запроса по MODBUS.
   * Можно послать любой запрос, достаточно просто сформировать буфер
   * @param raw_request -- буфер сырого запроса
   * @param raw_request_size -- размер буфера сырого запроса
   * @param raw_response -- буфер сырого ответа
   * @param raw_response_size -- размер буфера сырого ответа
   * @return true, если все прошло без ошибок, иначе -- false
   */
  bool sendRawRequest(uint8_t *raw_request, uint16_t raw_request_size,
                      uint8_t *raw_response, uint16_t &raw_response_size);

  /**
   * Метод для обновления ендпоинта и сокета в соответствие с актуальными значениями
   * IP и порта
   */
  void update();

  ModbusResult handleError(uint8_t *request,
                           uint16_t request_size,
                           uint8_t *response,
                           uint16_t response_size);

};
}
#endif //DIALTEK_COMPONENTS_LIBMODBUS
