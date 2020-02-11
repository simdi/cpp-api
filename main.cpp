#include "crow_all.h"

int main(int argc, char* argv[]) {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](){
    return "<div><h1>Hello from crow</h1></div>";
  });

  char* port = getenv("PORT");
  uint16_t iPort = static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18080);
  std::cout << "Application running on port: " << iPort << std::endl;

  app.port(iPort).multithreaded().run();
}