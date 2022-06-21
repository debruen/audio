
#include "program.h"

Program::Program() {
}

void Program::scan_devices() {

  _input_devices.clear();
  _output_devices.clear();

  // Determine the number of devices available
  unsigned int devices = _dac.getDeviceCount();

  // scan_devices through devices for various capabilities
  RtAudio::DeviceInfo info;

  for (unsigned int i = 0; i < devices; i++) {
    info = _dac.getDeviceInfo(i);
    if (info.probed == true) {
      nlohmann::json element;

      element["name"]   = info.name;
      element["index"]  = i;
      element["input"]  = info.inputChannels;
      element["output"] = info.outputChannels;

      if(info.inputChannels > 0) _input_devices.push_back(element);
      if(info.outputChannels > 0) _output_devices.push_back(element);
    }
  }

}

nlohmann::json Program::input(nlohmann::json data) {
  scan_devices();

  nlohmann::json response;

  if (data["select"]) {
    response["select"] = data["select"];
  } else {
    response["select"] = _dac.getDefaultInputDevice();
  }

  _input = response["select"];

  response["devices"] = _input_devices;

  return response;
}

nlohmann::json Program::output(nlohmann::json data) {
  scan_devices();

  nlohmann::json response;

  if (data["select"]) {
    response["select"] = data["select"];
  } else {
    response["select"] = _dac.getDefaultOutputDevice();
  }

  _output = response["select"];

  response["devices"] = _output_devices;

  return response;
}
