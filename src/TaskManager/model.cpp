#include "model.h"

void ModelTaskManager::TakeSignal(std::string command) {
    ExecuteSignal(command);
}

void ModelTaskManager::ReadInfoFromFile() {
    std::ifstream fin;
    std::string tmp_string;
    fin.open(file_path);
    string_collection.clear();

    if (!fin.is_open()) {
        std::cout << "Cannot open the file!" << std::endl;
    } else {
        while (!fin.eof()) {
            tmp_string = "";
            std::getline(fin, tmp_string);
            string_collection.push_back(tmp_string);
        }
    }
    fin.close();
}

void ModelTaskManager::ExecuteSignal(std::string signal) {
    signal += " >> ../TaskManager/info.txt";
    system("> ../TaskManager/info.txt");
    system(signal.c_str());
}

void ModelTaskManager::SetSignal(int new_signal) {
    signal_ = new_signal;
}

void ModelTaskManager::SetPID(int new_PID) {
    current_PID = new_PID;
}

void ModelTaskManager::SetStringCollection(std::vector<std::string> new_collection) {
    string_collection = new_collection;
}

int ModelTaskManager::GetSignal() {
    return signal_;
}

int ModelTaskManager::GetPID() {
    return current_PID;
}

std::vector<std::string> ModelTaskManager::getStringCollection() {
    return string_collection;
}
