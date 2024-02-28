#ifndef DIALTEK_COMPONENTS_LIBMODBUS_TCP_SOCKET_H_
#define DIALTEK_COMPONENTS_LIBMODBUS_TCP_SOCKET_H_

#include <boost/noncopyable.hpp>
#include <boost/enable_shared_from_this.hpp>

#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/bind/bind.hpp>

#include <iostream>

using namespace boost;
using namespace boost::system;
using namespace boost::asio;
using namespace boost::asio::ip;

// TODO: Добавить в этот класс ещё асинхронную запись с таймаутом

/**
 * Вспомогательный класс для более удобной работы с сокетом.
 * Полезен для более удобного осуществления асинхронного чтения с таймаутом
 */
class TcpConnection: public boost::enable_shared_from_this<TcpConnection>, boost::noncopyable {
 public:
  /**
   * Метод для того, чтобы делать асинхронное чтение и ждать какой-то таймаут. Со стороны это
   * чтение выглядит как синхронное с таймаутом.
   * @tparam MutableBufferSequence -- тип сокета
   * @param sock -- сокет
   * @param buffers -- буффер, в который запишутся данные, если будут
   * @param timeout -- таймаут, который будет работать метод, если не будет получать данных
   * @param io -- по сути контекст сокета (io_service)
   * @return количествео прочитанных байт
   */
  template <typename MutableBufferSequence>
  size_t read_with_timeout(boost::asio::ip::tcp::socket& sock,
                        const MutableBufferSequence& buffers,
                        size_t timeout,
                        io_service &io) {
    deadline_timer timer(io);
    received_bytes = 0;

    bool data_available;
    sock.async_read_some(buffers,
                        boost::bind(&TcpConnection::readCallback, this, boost::ref(data_available),
                                    boost::ref(timer),
                                    boost::asio::placeholders::error,
                                    boost::asio::placeholders::bytes_transferred));
    timer.expires_from_now(boost::posix_time::seconds(timeout));
    timer.async_wait(boost::bind(&TcpConnection::waitCallback, this, boost::ref(sock),
                                boost::asio::placeholders::error));

    io.reset();
    io.run();
    return received_bytes;
  }

  void connect(boost::beast::tcp_stream& stream, ip::tcp::endpoint &ep, io_service &io) {
    io.reset();
    io.run();


    stream.expires_after(std::chrono::seconds(4));
    stream.async_connect(ep, [&] (beast::error_code _ec) {
      std::cout << "TTTTT" << std::endl;
      if (_ec == beast::error::timeout) {
        std::cerr << "TILTTT" << std::endl;
        stream.close();
      }
    });

    io.reset();
  }

 private:
  size_t received_bytes;

  void readCallback(bool& data_available, deadline_timer& timeout, const boost::system::error_code& error, std::size_t bytes_transferred) {
    if (error || !bytes_transferred) {
     // No data was read!
     data_available = false;
     return;
    }

    received_bytes += bytes_transferred;
//    std::cout << bytes_transferred << " " << received_bytes << std::endl;
    timeout.cancel();  // will cause waitCallback to fire with an error
    data_available = true;
  }

  void waitCallback(boost::asio::ip::tcp::socket &sock, const boost::system::error_code& error) {
    if (error) {
      // Data was read and this timeout was canceled
      return;
    }

    sock.cancel();  // will cause readCallback to fire with an error
  }
};

#endif //DIALTEK_COMPONENTS_LIBMODBUS_TCP_SOCKET_H_
