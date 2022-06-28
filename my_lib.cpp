#include "my_lib.h"
#include <iostream>
#include "spdlog/spdlog.h"
#include "config.hpp"

void printHelloWord()
{
    spdlog::info("Welcome to spdlog!");
    std::cout << "hello world" << std::endl;
    std::cout << MYVAR << std::endl;
}
