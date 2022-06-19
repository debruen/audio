
#ifndef program_h
#define program_h

#include "nlohmann/json.hpp"
#include "rtaudio/RtAudio.h"

class Program {

  private:

    RtAudio _audio;

    std::vector<RtAudio::DeviceInfo> _inputs;
    std::vector<RtAudio::DeviceInfo> _outputs;

    void scan();

  public:
    Program();

    nlohmann::json init();
    nlohmann::json data(nlohmann::json data);

    nlohmann::json input(nlohmann::json data);
    nlohmann::json output(nlohmann::json data);

};

#endif /* program_h */
