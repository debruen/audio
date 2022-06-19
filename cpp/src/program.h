
#ifndef program_h
#define program_h

#include "nlohmann/json.hpp"

class Program {

  private:

    nlohmann::json _data;

  public:
    Program();

    nlohmann::json init();
    nlohmann::json data(nlohmann::json data);

};

#endif /* program_h */
