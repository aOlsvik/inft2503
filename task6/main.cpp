#include <boost/asio.hpp>
#include <iostream>

using namespace std;
using namespace boost::asio::ip;

class HTTPServer {
private:
  class Connection {
  public:
    tcp::socket socket;
    Connection(boost::asio::io_service &io_service) : socket(io_service) {}
  };

  boost::asio::io_service io_service;

  tcp::endpoint endpoint;
  tcp::acceptor acceptor;

  void handle_request(shared_ptr<Connection> connection) {
    auto read_buffer = make_shared<boost::asio::streambuf>();
    // Read from client until newline ("\r\n")
    async_read_until(connection->socket, *read_buffer, "HTTP/1.1",
                     [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                       // If not error:
                       if (!ec) {
                         // Retrieve message from client as string:
                         istream read_stream(read_buffer.get());
                         std::string message;
                         getline(read_stream, message);
                         message.pop_back(); // Remove "\r" at the end of message

                         cout << "Message from a connected client: " << message << endl;

                         auto write_buffer = make_shared<boost::asio::streambuf>();
                         ostream write_stream(write_buffer.get());

                         std::string response;
                         // Add message to be written to client:
                         if (message == "GET / HTTP/1.1") {
                           response = "Dette er hovedsiden";
                         } else if (message == "GET /en_side HTTP/1.1") {
                           response = "Dette er en annen side";
                         }

                         if (!response.empty()) {
                           write_stream << response;
                         } else {
                           std::ostringstream fail_response;
                           std::string responsebody("<html><body><h1>404 Not Found</h1></body></html>");

                           // HTTP Status Line: "HTTP/1.1 404 Not Found"
                           fail_response << "HTTP/1.1 404 Not Found\r\n";

                           // HTTP Headers
                           fail_response << "Content-Type: text/html\r\n";                       // Specify the content type
                           fail_response << "Content-Length: " << responsebody.size() << "\r\n"; // Set the content length (adjust as needed)
                           fail_response << "Connection: close\r\n";                             // Close the connection after sending

                           // Empty line to separate headers from the body
                           fail_response << "\r\n";

                           // HTTP Response Body
                           fail_response << "<html><body><h1>404 Not Found</h1></body></html>";

                           // Convert the response to a string
                           std::string responseStr = fail_response.str();
                           write_stream << responseStr;
                         }

                         // Write to client
                         async_write(connection->socket, *write_buffer,
                                     [connection, write_buffer](const boost::system::error_code &ec, size_t) {
                                       // If not error:
                                       if (!ec)
                                         return;
                                     });
                         return;
                       }
                     });
  }

  void accept() {
    // The (client) connection is added to the lambda parameter and handle_request
    // in order to keep the object alive for as long as it is needed.
    auto connection = make_shared<Connection>(io_service);

    // Accepts a new (client) connection. On connection, immediately start accepting a new connection
    acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
      accept();
      // If not error:
      if (!ec) {
        handle_request(connection);
      }
    });
  }

public:
  HTTPServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

  void start() {
    accept();

    io_service.run();
  }
};

int main() {
  HTTPServer http_server;

  cout << "Starting HTTP server" << endl
       << "Go to localhost:8080/ in a browser" << endl;

  http_server.start();
}
