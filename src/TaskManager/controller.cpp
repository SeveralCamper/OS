#include "controller.h"

void Controller::TakeSignal(int signal, int PID, std::string command) {
    model->TakeSignal(signal, PID, command);
}

void Controller::SetSignal(int new_signal) {
    model->SetSignal(new_signal);
}

void Controller::SetPID(int new_PID) {
    model->SetPID(new_PID);
}

int Controller::GetSignal() {
    return model->GetSignal();
}

int Controller::GetPID() {
    return model->GetPID();
}
