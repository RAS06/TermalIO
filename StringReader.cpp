//UNUSED BY FAILURE

#include <iostream>
#include <utility>
#include "StringReader.h"

std::basic_string<char> readCurr(std::string in) {
    StringReader::curr = std::move(in);
    std::cout << StringReader::curr << std::endl;
    //seekReaction(curr);
}

std::string StringReader::seekReaction(const std::string &changeState) {
    std::cout << changeState << std::endl;
    return "";
}
