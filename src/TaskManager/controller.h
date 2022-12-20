#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.h"

class Controller
{
public:
    Controller();
    Controller(ModelTaskManager *model) : model(model){};
    Controller(const Controller& other) = delete;
    Controller(Controller&& other) = delete;
    ~Controller() = default;

    void TakeSignal(int signal, int PID, std::string commad);
    void ExecuteSignal(std::string signal);
    void SetSignal(int new_signal);
    void SetPID(int new_PID);

    int GetSignal();
    int GetPID();
private:
    ModelTaskManager *model;
};

#endif // CONTROLLER_H
