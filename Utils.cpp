//
// Created by benjamin on 8/17/18.
//

#include <sstream>
#include "Utils.h"

vector<string> split(string str, char delim) {
    stringstream test(str);
    string current;
    std::vector<std::string> seglist;

    while(getline(test, current, delim)) {
        seglist.push_back(current);
    }
    return seglist;
}
