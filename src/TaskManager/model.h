#pragma once

#include <iostream>
#include <string>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <fstream>
#include <vector>

class ModelTaskManager {
    public:
        ModelTaskManager() = default;
        ModelTaskManager(const ModelTaskManager& other) = delete;
        ModelTaskManager(ModelTaskManager&& other) = delete;
        ~ModelTaskManager() = default;

        void SetStringCollection(std::vector<std::string> new_collection);
        void TakeSignal(std::string command);
        void SetSignal(int new_signal);
        void SetPID(int new_PID);
        void ReadInfoFromFile();

        int GetSignal();
        int GetPID();

        std::vector<std::string> getStringCollection();

    private:
        int signal_ = 0;
        int current_PID = 0;

        std::string file_path = "../TaskManager/info.txt";
        std::vector<std::string> string_collection;

        void ExecuteSignal(std::string signal);
};
