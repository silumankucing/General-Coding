#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

using namespace std;

// Define a WebSocket server class
class WebSocketServer {
public:
    WebSocketServer() {
        // Set up WebSocket server
        server.init_asio();
        server.set_message_handler(bind(&WebSocketServer::on_message, this, placeholders::_1, placeholders::_2));
    }

    void run(uint16_t port) {
        // Start the server
        server.listen(port);
        server.start_accept();
        server.run();
    }

private:
    // WebSocket message handler
    void on_message(websocketpp::connection_hdl hdl, websocketpp::server<websocketpp::config::asio>::message_ptr msg) {
        // Echo the received message back to the client
        server.send(hdl, msg->get_payload(), msg->get_opcode());
    }

    // WebSocket server instance
    websocketpp::server<websocketpp::config::asio> server;
};

int main() {
    // Create and run the WebSocket server on port 9002
    WebSocketServer server;
    server.run(9002);

    return 0;
}
