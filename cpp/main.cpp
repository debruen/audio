
#include "async.h"

// init Program class
Program program;

// -- -- -- -- -- init
Napi::Value program_init(const Napi::CallbackInfo& info) {
  Napi::Function callback = info[0].As<Napi::Function>();

  AsyncInit* init_synthesis = new AsyncInit(callback, program);
  init_synthesis->Queue();

  std::string msg = "init";
  return Napi::String::New(info.Env(),msg.c_str());
};

// -- -- -- -- -- data
Napi::Value program_data(const Napi::CallbackInfo& info) {
  std::string string = info[0].As<Napi::String>().Utf8Value();
  Napi::Function callback = info[1].As<Napi::Function>();

  nlohmann::json json = nlohmann::json::parse(string);

  AsyncData* data_synthesis = new AsyncData(callback, program, json);
  data_synthesis->Queue();

  std::string msg = "program: data synthesis";
  return Napi::String::New(info.Env(),msg.c_str());
};

Napi::Object Init(Napi::Env env, Napi::Object exports) {

  exports["program_init"] = Napi::Function::New(env, program_init, std::string("program_init"));
  exports["program_data"] = Napi::Function::New(env, program_data, std::string("program_data"));

  return exports;
}

NODE_API_MODULE(addon, Init)
