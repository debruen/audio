#ifndef async_h
#define async_h

#include <napi.h>

#include <chrono>
#include <thread>
#include <iomanip>

#include "src/program.h"

// -- -- -- -- -- init
class AsyncInit : public Napi::AsyncWorker {

  private:
    Program& program;
    nlohmann::json m_data;

  public:
    AsyncInit(Napi::Function& callback, Program& program)
      : AsyncWorker(callback), program(program) {
    };
    virtual ~AsyncInit() {};

    void Execute() {
      m_data = program.init();
    };
    void OnOK() {
      std::string string = m_data.dump();
      Callback().Call({Env().Null(), Napi::String::New(Env(), string)});
    };
};

// -- -- -- -- -- data
class AsyncData : public Napi::AsyncWorker {

  private:
    Program& program;
    nlohmann::json m_data;

  public:
    AsyncData(Napi::Function& callback, Program& program, nlohmann::json data)
      : AsyncWorker(callback), program(program), m_data(data) {
    };
    virtual ~AsyncData() {};

    void Execute() {
      m_data = program.data(m_data);
    };
    void OnOK() {
      std::string string = m_data.dump();
      Callback().Call({Env().Null(), Napi::String::New(Env(), string)});
    };
};

#endif
