# cpp-api
## Web API Server with C++

### How to run the app
- docker build cppapi
- docker run -v <HOST /Users/computer/desktop/projects/cpp/cpp-api>:<CONTAINER /usr/src/cpp-api> -p 8080:8080 -e PORT=8080 cppapi:latest <PATH_TO_BUILD /usr/src/cpp-api/build/cppapi>
