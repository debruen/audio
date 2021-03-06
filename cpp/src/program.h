
#ifndef program_h
#define program_h

#include "nlohmann/json.hpp"
#include "rtaudio/RtAudio.h"

class Program {

  private:

    RtAudio _dac;

    int _input  = _dac.getDefaultInputDevice();
    int _output = _dac.getDefaultOutputDevice();

    std::vector<nlohmann::json> _input_devices;
    std::vector<nlohmann::json> _output_devices;

    void scan_devices();

  public:
    Program();

    nlohmann::json input(nlohmann::json data);
    nlohmann::json output(nlohmann::json data);

    void stream(); // Duplex !!
    void record();
    bool stop();

};

#endif /* program_h */
