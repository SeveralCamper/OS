#include "model.h"

void ModelTaskManager::TakeSignal(int signal, int PID, std::string command) {
    std::string command_1 = "ps -p ";
    std::string command_2 = "kill ";
    switch(signal) {
        case 1:
            std::cout << std::endl;
            std::cout << "Show all process:" << std::endl;
            std::cout << std::endl;
            ExecuteSignal(command);
            break;
        case 2:
            std::cout << std::endl;
            std::cout << "Show all process in directory:" << std::endl;
            std::cout << std::endl;
            ExecuteSignal(command);
            break;
        case 3:
            std::cout << std::endl;
            std::cout << "Show process tree with PID:" << std::endl;
            std::cout << std::endl;
            ExecuteSignal(command);
            break;
        case 4:
            std::cout << std::endl;
            std::cout << "Shown own process:" << std::endl;
            std::cout << "Your porcess PID is:" << (int)getpid() << std::endl;
            std::cout << std::endl;
            break;
        case 5:
            // std::system("whoami");
            std::cout << std::endl;
            std::cout << "Show process by PID:" << std::endl;
            std::cout << std::endl;

            ExecuteSignal(command);
            break;
        case 6:
            std::cout << std::endl;
            std::cout << "Delete process by PID:" << std::endl;
            std::cout << std::endl;
            ExecuteSignal(command);
            break;
        case 0:
            exit(0);
            break;
        default:
            break;
    }
}

void ModelTaskManager::ExecuteSignal(std::string signal) {
    signal += " >> ../TaskManager/info.txt";
    // std::cout << signal << std::endl;
    system("> ../TaskManager/info.txt");
    system(signal.c_str());
}

void ModelTaskManager::SetSignal(int new_signal) {
    signal_ = new_signal;
}

void ModelTaskManager::SetPID(int new_PID) {
    current_PID = new_PID;
}

int ModelTaskManager::GetSignal() {
    return signal_;
}

int ModelTaskManager::GetPID() {
    return current_PID;
}
