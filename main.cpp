#include <iostream>
#include <fstream>
#include <string>

std::string curr;

bool validateInput(const std::string&);
std::basic_string<char> readCurr(std::string);
std::string seekReaction(std::string);


int main() {
    std::string in;
    while(!getline(std::cin, in).eof()){
        std::cout<< seekReaction(in) << std::endl;
    }
    return 0;
}

std::string seekReaction(std::string in) {
    curr = in;
    if(validateInput(curr)){
        std::cout<<"True"<<std::endl;
    } else {
        return "Try another command please.";
    }
    return "";
}
bool validateInput(const std::string& target){
    std::ifstream validatorTraversal;
    validatorTraversal.open("validCommands.txt");
    std::string readingLine;
    if(validatorTraversal.is_open()){
        while (getline (validatorTraversal,readingLine) )
        {
            if(target == readingLine){
                return true;
            }
        }
    }
    validatorTraversal.close();
    return false;
}
