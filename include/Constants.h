#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <vector>

using namespace Constants {
  const std::vector<char> VALID_CHARS = {
    'A', 'B', 'C', 'D', 'E', 
    'F', 'G', 'H', 'I', 'J', 
    'K', 'L', 'M', 'N', 'O', 
    'P', 'Q', 'R', 'S', 'T', 
    'U', 'V', 'W', 'X', 'Y'
  };
  
  map<char, vector<char>> graph = {
    {'A', {'B', 'C'}},
    {'B', {}},
    {'C', {'D', 'E'}},
    {'D', {}},
    {'E', {'F', 'I'}},
    {'F', {'G', 'H'}},
    {'G', {}},
    {'H', {}},
    {'I', {'J', 'K', 'L'}},
    {'J', {}},
    {'K', {}},
    {'L', {'M'}},
    {'M', {'N'}},
    {'N', {'O', 'P'}},
    {'O', {}},
    {'P', {'Q', 'S'}},
    {'Q', {'R'}},
    {'R', {}},
    {'S', {'T', 'U'}},
    {'T', {}},
    {'U', {'V'}},
    {'V', {'X', 'W'}},
    {'W', {}},
    {'X', {'Y'}},
    {'Y', {}}
  };

}

#endif // CONSTANTS_H