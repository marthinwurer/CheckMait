//
// Created by benjamin on 8/17/18.
//

#include <sstream>
#include "Utils.h"

vector<string> split(const string &str, char delimiter) {
    stringstream test(str);
    string current;
    std::vector<std::string> seg_list;

    while(getline(test, current, delimiter)) {
        seg_list.push_back(current);
    }
    return seg_list;
}
