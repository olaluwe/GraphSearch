#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Include.h>

using namespace std;

class Constants {
  public:
    const int MIN_VALUE = 1;
    const int MAX_VALUE = 5;
    const std::vector<char> VALID_CHARS = {
      'A', 'B', 'C', 'D', 'E', 
      'F', 'G', 'H', 'I', 'J', 
      'K', 'L', 'M', 'N', 'O', 
      'P', 'Q', 'R', 'S', 'T', 
      'U', 'V', 'W', 'X', 'Y'
    };

    const std::vector<char> validResponse = {'N', 'Y'};
    
    const std::map<char, std::vector<char>> graph = {
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

    const std::vector<std::string> CITIES = {
      "Arad",
      "Bucharest",
      "Craiova",
      "Drobeta",
      "Eforie",
      "Fagaras",
      "Giurgiu",
      "Hirsova",
      "Iasi",
      "Lugoj",
      "Mehadia",
      "Neamt",
      "Oradea",
      "Pitesti",
      "Rimnicu Vilcea",
      "Sibiu",
      "Timisoara",
      "Urziceni",
      "Vaslui",
      "Zerind"
    };

    const Graph RomaniaMap = {
      {"Arad", {{"Zerind", 75}, {"Sibiu", 140}, {"Timisoara", 118}}},
      {"Zerind", {{"Arad", 75}, {"Oradea", 71}}},
      {"Oradea", {{"Zerind", 71}, {"Sibiu", 151}}},
      {"Sibiu", {{"Arad", 140}, {"Oradea", 151}, {"Fagaras", 99}, {"Rimnicu Vilcea", 80}}},
      {"Rimnicu Vilcea", {{"Sibiu", 80}, {"Pitesti", 97}, {"Craiova", 146}}},
      {"Craiova", {{"Rimnicu Vilcea", 146}, {"Pitesti", 138}, {"Drobeta", 120}}},
      {"Drobeta", {{"Craiova", 120}, {"Mehadia", 75}}},
      {"Mehadia", {{"Drobeta", 75}, {"Lugoj", 70}}},
      {"Lugoj", {{"Mehadia", 70}, {"Timisoara", 111}}},
      {"Timisoara", {{"Arad", 118}, {"Lugoj", 111}}},
      {"Fagaras", {{"Sibiu", 99}, {"Bucharest", 211}}},
      {"Pitesti", {{"Craiova", 138}, {"Rimnicu Vilcea", 97}, {"Bucharest", 101}}},
      {"Bucharest", {{"Fagaras", 211}, {"Pitesti", 101}, {"Giurgiu", 90}, {"Urziceni", 85}}},
      {"Giurgiu", {{"Bucharest", 90}}},
      {"Urziceni", {{"Bucharest", 85}, {"Vaslui", 142}, {"Hirsova", 98}}},
      {"Hirsova", {{"Urziceni", 98}, {"Eforie", 86}}},
      {"Eforie", {{"Hirsova", 86}}},
      {"Vaslui", {{"Urziceni", 142}, {"Iasi", 92}}},
      {"Iasi", {{"Vaslui", 92}, {"Neamt", 87}}},
      {"Neamt", {{"Iasi", 87}}}
    };

    std::map<std::string, int> Heuristics = {
      {"Arad", 366},
      {"Bucharest", 0},
      {"Craiova", 160},
      {"Drobeta", 242},
      {"Eforie", 161},
      {"Fagaras", 176},
      {"Giurgiu", 77},
      {"Hirsova", 151},
      {"Iasi", 226},
      {"Lugoj", 244},
      {"Mehadia", 241},
      {"Neamt", 234},
      {"Oradea", 380},
      {"Pitesti", 100},
      {"Rimnicu Vilcea", 193},
      {"Sibiu", 253},
      {"Timisoara", 329},
      {"Urziceni", 80},
      {"Vaslui", 199},
      {"Zerind", 174}
    };

  };

#endif // CONSTANTS_H