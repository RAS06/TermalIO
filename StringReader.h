//UNUSED BY FAILURE

#ifndef TERMALIO_STRINGREADER_H
#define TERMALIO_STRINGREADER_H


class StringReader {
public:
    static std::string curr;
    static std::basic_string<char> readCurr(std::string);
    static std::string seekReaction(const std::string&);
};


#endif //TERMALIO_STRINGREADER_H
