//
// Created by Joaquín Marcher on 27.08.22.
//
#include "application.h"
#include "exception_handler.h"
#include <iostream>


void newredis::application::start() {
    std::string currentCommand;
    while(command_handler::isRunning(currentCommand)){
        std::cout << "NEWREDIS $ ";
        std::getline(std::cin, currentCommand);
        try {
            commandHandler.handleCommand(currentCommand);
        }catch (std::exception& e){
            exception_handler::handle(e);
        }
    }
}

void newredis::application::cleanUp() {

}
