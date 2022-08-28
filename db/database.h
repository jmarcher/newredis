//
// Created by Joaquín Marcher on 27.08.22.
//

#ifndef NEW_REDIS_DATABASE_H
#define NEW_REDIS_DATABASE_H

#include <string>
#include <map>

namespace newredis {
    class database {
    public:
        static database& instance(){
            static database _instance;
            return _instance;
        }
        bool set(const std::string& key, const std::string& value);
        const std::string& get(const std::string& key);
        bool remove(const std::string& key);


    private:
        database(){}
        std::map<std::string,std::string> table{};
        database(database const&);
        void operator=(database const&);
    };
}


#endif //NEW_REDIS_DATABASE_H
