
#include "program.h"

Program::Program() {
  _data = 0;
}


nlohmann::json Program::init() {
  return _data;
}

nlohmann::json Program::data(nlohmann::json data) {

  _data = data;

  return _data;
}
