#ifndef async_h
#define async_h

#include <napi.h>

#include <chrono>
#include <thread>
#include <iomanip>

#include "src/program.h"

class AsyncInput : public Napi::AsyncWorker {

  private:
    Program& program;
    nlohmann::json m_data;

  public:
    AsyncInput(Napi::Function& callback, Program& program, nlohmann::json data)
      : AsyncWorker(callback), program(program), m_data(data) {
    };
    virtual ~AsyncInput() {};

    void Execute() {
      m_data = program.input(m_data);
    };
    void OnOK() {
      std::string string = m_data.dump();
      Callback().Call({Env().Null(), Napi::String::New(Env(), string)});
    };
};

class AsyncOutput : public Napi::AsyncWorker {

  private:
    Program& program;
    nlohmann::json m_data;

  public:
    AsyncOutput(Napi::Function& callback, Program& program, nlohmann::json data)
      : AsyncWorker(callback), program(program), m_data(data) {
    };
    virtual ~AsyncOutput() {};

    void Execute() {
      m_data = program.output(m_data);
    };
    void OnOK() {
      std::string string = m_data.dump();
      Callback().Call({Env().Null(), Napi::String::New(Env(), string)});
    };
};

#endif
