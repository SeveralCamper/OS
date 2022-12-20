#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <fstream>

class ModelTaskManager {
    public:
        ModelTaskManager() = default;
        ModelTaskManager(const ModelTaskManager& other) = delete;
        ModelTaskManager(ModelTaskManager&& other) = delete;
        ~ModelTaskManager() = default;

        void TakeSignal(int signal, int PID, std::string command);
        void SetSignal(int new_signal);
        void SetPID(int new_PID);

        int GetSignal();
        int GetPID();

    private:
        int signal_ = 0;
        int current_PID = 0;

        void ExecuteSignal(std::string signal);
};
