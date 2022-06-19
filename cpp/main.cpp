
#include "async.h"

// init Program class
Program program;


Napi::Value input(const Napi::CallbackInfo& info) {
  std::string string = info[0].As<Napi::String>().Utf8Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  nlohmann::json json = nlohmann::json::parse(string);

  AsyncInput* audio_input = new AsyncInput(callback, program, json);
  audio_input->Queue();

  std::string msg = "program: data synthesis";
  return Napi::String::New(info.Env(),msg.c_str());
};

Napi::Value output(const Napi::CallbackInfo& info) {
  std::string string = info[0].As<Napi::String>().Utf8Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  nlohmann::json json = nlohmann::json::parse(string);

  AsyncOutput* audio_output = new AsyncOutput(callback, program, json);
  audio_output->Queue();

  std::string msg = "program: data synthesis";
  return Napi::String::New(info.Env(),msg.c_str());
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {

  exports["input"] = Napi::Function::New(env, input, std::string("input"));
  exports["output"] = Napi::Function::New(env, output, std::string("output"));

  return exports;
}

NODE_API_MODULE(addon, Init)
