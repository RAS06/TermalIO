#include <iostream>
#include <fstream>
#include <string>

std::string curr;
bool started = false;
int systemState;

bool validateInput(const std::string&);
std::string seekReaction(std::string);
void generateResponse(const std::string&);
void writeStartMessage();
void getAreaDescription();
int assignID(const std::string&);

int main() {
    std::string in;
    while(!getline(std::cin, in).eof()){
        std::cout << seekReaction(in) << std::endl;
    }
    return 0;
}
std::string seekReaction(std::string in) {
    curr = in;
    if(validateInput(curr)){
        generateResponse(curr);
    } else {
        return "Try another command please.";
    }
    return "";
}
void generateResponse(const std::string& strIn) {
    int strID = assignID(strIn);
    if(strIn == "start" && !started){
        started = true;
        writeStartMessage();
    } else if(started){
        switch(strID){
            case(558):
                std::cout << "Program already started." << std::endl;
                break;
            case(1118):
                getAreaDescription(); // Always Valid.
                break;
            default:
                std::cout << "Please try a different command" << std::endl;
        }
    }
}
void getAreaDescription() {
    std::ifstream areaDescriber;
    areaDescriber.open(std::string("validCommandsPerContext/area") + std::to_string(systemState) + std::string(".txt"));
    if(areaDescriber.is_open()){
        std::string line;
        getline(areaDescriber, line);
        std::cout << line << std::endl;
    }
}
int assignID(const std::string& values) {
    int sum = 0;
    for(char value : values){
        sum += (int)value;
    }
    return sum;
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
void writeStartMessage(){
    std::ifstream reader;
    reader.open("validCommandsPerContext/start.txt");
    if(reader.is_open()) {
        std::string line;
        getline(reader, line);
        std::cout << line << std::endl;
    }
    reader.close();
    systemState = 0;
}