#include "../include/Misc.h"
#include "Misc.h"

void Misc::printPath(const std::vector<char>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) { // Check if it's not the last node
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

void Misc::printPath(const std::vector<std::string>& path) {
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1) { // Check if it's not the last node
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;
}

int Misc::getValidInt(std::string prompt, int minValue, int maxValue) 
{
    int value;

    do {
        std::cout << prompt;
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    } while (std::cin.fail() || value < minValue || value > maxValue);

    return value;
}

// Function to convert a valid string from the user to Titlecase format
std::string Misc::titleCase(const std::string& str) {
    if (str.empty()) return "";
    std::string result = str;
    result[0] = std::toupper(result[0]);
    for (size_t i = 1; i < result.length(); ++i) {
        result[i] = std::tolower(result[i]);
    }
    return result;
}

char Misc::getValidChar(const std::string& prompt, const std::vector<char>& targetChars) {
    std::string input;

    while (true) { // Use an infinite loop that returns on valid input
        std::cout << prompt;
        std::getline(std::cin, input); // Read the whole line into input

        if (input.length() == 1) {
            char inputChar = std::toupper(input[0]); // Convert to uppercase to simplify comparison

            // Use std::find to search for inputChar in targetChars
            auto it = std::find_if(targetChars.begin(), targetChars.end(), 
                                   [inputChar](char c) { return std::toupper(c) == inputChar; });

            if (it != targetChars.end()) {
                return *it; // Return the valid character from targetChars
            }
        }

        std::cout << "Invalid input. Please try again.\n";
    }
}

// Function to get a valid string from the user that matches one of the strings in vectorStrings
std::string Misc::getValidString(const std::string& prompt, const std::vector<std::string>& vectorStrings) {
  std::string myString;
  bool found = false;
  do {
    std::cout << prompt;
    std::getline(std::cin, myString);
    if (myString.empty()) {
      continue; // Prompt again if the input is empty
    }
    myString = titleCase(myString); // Convert user input to title case for comparison
    for (const auto& targetString : vectorStrings) {
      if (myString == titleCase(targetString)) { // Convert targetString to title case for a case-insensitive comparison
        found = true;
        break;
      }
    }
    if (!found) {
      std::cout << "Input not valid. Please try again.\n";
    }
  } while (!found);
  return myString;
}
