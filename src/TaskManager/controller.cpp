#include "controller.h"

void Controller::TakeSignal(std::string command) {
    model->TakeSignal(command);
}

void Controller::SetSignal(int new_signal) {
    model->SetSignal(new_signal);
}

void Controller::SetPID(int new_PID) {
    model->SetPID(new_PID);
}


void Controller::ReadInfoFromFile() {
    model->ReadInfoFromFile();
}

void Controller::SetStringCollection(std::vector<std::string> new_collection) {
    model->SetStringCollection(new_collection);
}

int Controller::GetSignal() {
    return model->GetSignal();
}

int Controller::GetPID() {
    return model->GetPID();
}

std::vector<std::string> Controller::getStringCollection() {
    return model->getStringCollection();
}
