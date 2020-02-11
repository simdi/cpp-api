#include "crow_all.h"

int main(int argc, char* argv[]) {
  crow::SimpleApp app;

  CROW_ROUTE(app, "/")([](const crow::request &req, crow::response &res){
    std::ifstream in("../public/index.html", std::ifstream::in);
    // if (in) {
      std::ostringstream contents;
      contents << in.rdbuf();
      in.close();
      std::cout << contents.str() << std::endl;
      res.write(contents.str());
    // } else {
    //   res.write("Not something Found");
    // }
    res.end();
  });

  char* port = getenv("PORT");
  uint16_t iPort = static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18080);
  std::cout << "Application running on port: " << iPort << std::endl;

  app.port(iPort).multithreaded().run();
}