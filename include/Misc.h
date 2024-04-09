#ifndef MISC_H
#define MISC_H

#include <Include.h>

using namespace std;

class Misc
{
  public:
    char getValidChar(const std::string&, const std::vector<char>&);
    std::string getValidString(const std::string&, const std::vector<std::string>&);
    void printPath(const vector<char>&);
    int getValidInt(std::string prompt, int minValue, int maxValue);
    void printPath(const vector<std::string> &);
    std::string titleCase(const std::string&);
};

#endif /*MISC_H*/
