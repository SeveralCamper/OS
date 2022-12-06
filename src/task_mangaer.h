#pragma once

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

void taskManager();
void parseManagerKey(std::string parse_string);
