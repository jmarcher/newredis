//
// Created by Joaquín Marcher on 27.08.22.
//

#include "database.h"

bool newredis::database::set(const std::string &key, const std::string &value) {
    table[key] = value;
    return true;
}

const std::string &newredis::database::get(const std::string &key) {
    std::string init;
    auto iterator = table.find(key);
    if(iterator == table.end()){
        return "";
    }
    return iterator->second;
}

bool newredis::database::remove(const std::string &key) {
    auto it = table.find(key);
    if(it == table.end()) return false;
    table.erase(table.find(key));
    return true;
}
