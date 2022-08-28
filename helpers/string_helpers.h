//
// Created by Joaquín Marcher on 27.08.22.
//

#ifndef NEW_REDIS_STRING_HELPERS_H
#define NEW_REDIS_STRING_HELPERS_H
#include <string>
#include <vector>
using namespace std;

class string_helpers {
public:
    static vector<string> split(const string& completeString, const string& delimiter) {
        size_t pos_start = 0, pos_end, delim_len = delimiter.length();
        string token;
        vector<string> res;

        while ((pos_end = completeString.find (delimiter, pos_start)) != string::npos) {
            token = completeString.substr (pos_start, pos_end - pos_start);
            pos_start = pos_end + delim_len;
            res.push_back (token);
        }

        res.push_back (completeString.substr (pos_start));
        return res;
    }

};


#endif //NEW_REDIS_STRING_HELPERS_H
