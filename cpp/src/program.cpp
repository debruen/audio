
#include "program.h"

Program::Program() {
}

void Program::scan() {

  // Determine the number of devices available
  unsigned int devices = _audio.getDeviceCount();
  // Scan through devices for various capabilities
  RtAudio::DeviceInfo info;
  for ( unsigned int i=0; i<devices; i++ ) {
    info = _audio.getDeviceInfo( i );
    if ( info.probed == true ) {
      // Print, for example, the maximum number of output channels for each device
      std::cout << "device = " << i;
      std::cout << ": maximum output channels = " << info.outputChannels << "\n";
    }
  }

}


nlohmann::json Program::input(nlohmann::json data) {
  return data;
}

nlohmann::json Program::output(nlohmann::json data) {


  return data;
}
