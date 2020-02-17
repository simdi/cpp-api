#include "crow_all.h"

void sendFile(crow::response &res, std::string filename, std::string contentType) {
  std::ifstream input("../public/" + filename, std::ifstream::in);

  if (input) {
    std::ostringstream contents;
    contents << input.rdbuf();
    input.close();
    std::cout << contents.str() << std::endl;
    res.set_header("Content-Type", contentType);
    res.write(contents.str());
  } else {
    res.code = 404;
    res.write("Not something Found");
  }
  res.end();
}

void sendHtml(crow::response &res, std::string filename) {
  sendFile(res, filename + ".html", "text/html");
}

void sendImages(crow::response &res, std::string filename) {
  sendFile(res, "images/" + filename, "images/jpeg");
}
void sendScripts(crow::response &res, std::string filename) {
  sendFile(res, "scripts/" + filename, "text/javascript");
}

void sendStyles(crow::response &res, std::string filename) {
  sendFile(res, "styles/" + filename, "text/css");
}

int main(int argc, char* argv[]) {
  std::cout << "argc: " << argc << " argv: " << argv << std::endl;
  crow::SimpleApp app;

  CROW_ROUTE(app, "/styles/<string>")([](const crow::request &req, crow::response &res, std::string filename){
    sendStyles(res, filename);
  });
  
  CROW_ROUTE(app, "/scripts/<string>")([](const crow::request &req, crow::response &res, std::string filename){
    sendScripts(res, filename);
  });

  CROW_ROUTE(app, "/images/<string>")([](const crow::request &req, crow::response &res, std::string filename){
    sendImages(res, filename);
  });

  CROW_ROUTE(app, "/")([](const crow::request &req, crow::response &res){
    sendHtml(res, "index");
  });

  char* port = getenv("PORT");
  uint16_t iPort = static_cast<uint16_t>(port != NULL ? std::stoi(port) : 18080);
  std::cout << "Application running on port: " << iPort << std::endl;

  app.port(iPort).multithreaded().run();
}