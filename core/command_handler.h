//
// Created by Joaquín Marcher on 27.08.22.
//

#ifndef NEW_REDIS_COMMAND_HANDLER_H
#define NEW_REDIS_COMMAND_HANDLER_H
#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include "../db/database.h"

typedef std::tuple<std::string, std::string, std::string> ch_command;

namespace newredis {
    class command_handler {
    public:

        void handleCommand(std::string& command);

        static bool isRunning(std::string& command){
            return command != "exit";
        }
    private:
        std::list<std::string> VALID_COMMANDS{"set", "get", "remove"};
        std::string COMMAND_DELIMITER = " ";
        bool validCommand(std::string& command);

        ch_command parseCommand(const std::string &basicString);
    };
}


#endif //NEW_REDIS_COMMAND_HANDLER_H
