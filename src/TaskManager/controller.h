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

    void SetStringCollection(std::vector<std::string> new_collection);
    void ExecuteSignal(std::string signal);
    void TakeSignal(std::string commad);
    void SetSignal(int new_signal);
    void SetPID(int new_PID);
    void ReadInfoFromFile();

    int GetSignal();
    int GetPID();
    std::vector<std::string> getStringCollection();

private:
    ModelTaskManager *model;
};

#endif // CONTROLLER_H
