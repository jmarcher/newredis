cmake_minimum_required(VERSION 3.23)
project(new_redis)

set(CMAKE_CXX_STANDARD 23)

add_executable(new_redis main.cpp core/application.cpp core/application.h core/command_handler.cpp core/command_handler.h core/exception_handler.cpp core/exception_handler.h db/database.cpp db/database.h helpers/string_helpers.h)
