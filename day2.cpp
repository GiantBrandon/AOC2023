#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>

bool is_number(const std::string& s) {
    for (int i = 0; i < s.length(); i++) {
        if(!std::isdigit(s[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int part1 = 0;
    int part2 = 0;
    std::string line;
    std::ifstream file("day2.txt");
    int index = 1;
    int lastNumber = -1;
    while (std::getline(file, line))
    {
        bool found = false;
        int minRed = 0;
        int minGreen = 0;
        int minBlue = 0;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            if (is_number(word)) {
                lastNumber = std::stoi(word);
            }
            if (word.substr(0, 3) == "red" && lastNumber > 12) {
                found = true;
            }
            else if (word.substr(0, 5) == "green" && lastNumber > 13) {
                found = true;
            }
            else if (word.substr(0, 4) == "blue"  && lastNumber > 14) {
                found = true;
            }
            if (word.substr(0, 3) == "red" && lastNumber > minRed) {
                minRed = lastNumber;
            }
            else if (word.substr(0, 5) == "green" && lastNumber > minGreen) {
                minGreen = lastNumber;
            }
            else if (word.substr(0, 4) == "blue"  && lastNumber > minBlue) {
                minBlue = lastNumber;
            }
        }
        if (!found) {
            part1 += index;
        }
        part2 += minRed * minGreen * minBlue;
        index++;
    }
    std::cout << part1 << std::endl;
    std::cout << part2 << std::endl;
  return 0;
}