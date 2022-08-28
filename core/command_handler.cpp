//
// Created by Joaquín Marcher on 27.08.22.
//
#include <stdexcept>
#include "command_handler.h"
#include "../helpers/string_helpers.h"
void newredis::command_handler::handleCommand(std::string &command) {
    // Return immediately if the command is an exit command
    if(! isRunning(command)) return;
    if(! validCommand(command)) throw std::invalid_argument("Command not recognized");
    ch_command parsedCommand = parseCommand(command);
    std::string commandName;
    if(std::get<0>(parsedCommand) == "set"){
        database::instance().set(std::get<1>(parsedCommand), std::get<2>(parsedCommand));
    }
    if(std::get<0>(parsedCommand) == "get"){
        // Print for debugging
        // TODO: Remove cout
        std::cout << database::instance().get(std::get<1>(parsedCommand)) << std::endl;
    }
    if(std::get<0>(parsedCommand) == "remove"){
        database::instance().remove(std::get<1>(parsedCommand));
    }
}

bool newredis::command_handler::validCommand(std::string &command) {
    std::string commandName = command.substr(0, command.find(COMMAND_DELIMITER));

    auto iterator = std::find(VALID_COMMANDS.begin(), VALID_COMMANDS.end(), commandName);

    return iterator != VALID_COMMANDS.end();
}

ch_command newredis::command_handler::parseCommand(const string &basicString) {
    u_int8_t position = 0;
    std::string commandCopy = basicString;
    std::string param;
    std::string param0;
    std::string param1;
    std::string param2;
    for(const char& c:basicString){
        if(c == ' '){
            switch (position) {
                case 0:
                    param0 = param;
                    break;
                case 1:
                    param1 = param;
                    break;
            }
            param = "";
            position++;
            if(position == 1){
                param2 = commandCopy.replace(0, param0.length() + param1.length() + 3, "");
                break;
            }
        }
        param.push_back(c);
    }
    ch_command result = {param0, param1, param2};
    return result;
}
