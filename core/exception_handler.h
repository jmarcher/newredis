//
// Created by Joaquín Marcher on 27.08.22.
//

#ifndef NEW_REDIS_EXCEPTION_HANDLER_H
#define NEW_REDIS_EXCEPTION_HANDLER_H

#include <stdexcept>
#include <iostream>
namespace newredis {

    class exception_handler {
    public:
        static void handle(std::exception& e){
            // simple log
            std::cout << e.what() << std::endl;
        }
    };

} // newredis

#endif //NEW_REDIS_EXCEPTION_HANDLER_H
