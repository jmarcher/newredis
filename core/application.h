//
// Created by Joaquín Marcher on 27.08.22.
//

#ifndef NEW_REDIS_APPLICATION_H
#define NEW_REDIS_APPLICATION_H
#include "command_handler.h"
#include <memory>

#include "../db/database.h"
namespace newredis {
    class application {
    public:
        void start();

        void cleanUp();
    private:
        command_handler commandHandler;
    };
}


#endif //NEW_REDIS_APPLICATION_H
