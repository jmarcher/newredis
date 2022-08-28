#include <iostream>
#include "core/application.h"

int main() {
    std::string command;
    newredis::application application;
    application.start();
    application.cleanUp();
    std::cout << "CleanUp completed, goodbye" << std::endl;
    return 0;
}
