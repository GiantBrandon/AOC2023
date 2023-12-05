#include <iostream>
#include <fstream>
#include <cctype>

int main() {
    int part1 = 0;
    int part2 = 0;
    std::string line;
    std::ifstream file("day1.txt");
    while (std::getline(file, line))
    {
        int first = -1;
        int last = -1;
        int first2 = -1;
        int last2 = -1;
        for (int i = 0; i < line.length(); i++) {
            int found = -1;
            if(isdigit(line[i])) {
                found = line[i] - '0';
            }
            if (found != -1) {
                if (first == -1) {
                    first = found;
                }
                last = found;
            }
            if(line.substr(i, 3) == "one") {
                found = 1;
            }
            if(line.substr(i, 3) == "two") {
                found = 2;
            }
            if(line.substr(i, 5) == "three") {
                found = 3;
            }
            if(line.substr(i, 4) == "four") {
                found = 4;
            }
            if(line.substr(i, 4) == "five") {
                found = 5;
            }
            if(line.substr(i, 3) == "six") {
                found = 6;
            }
            if(line.substr(i, 5) == "seven") {
                found = 7;
            }
            if(line.substr(i, 5) == "eight") {
                found = 8;
            }
            if(line.substr(i, 4) == "nine") {
                found = 9;
            }
            if (found != -1) {
                if (first2 == -1) {
                    first2 = found;
                }
                last2 = found;
            }
        }
        part1 += first * 10 + last;
        part2 += first2 * 10 + last2;
    }
    std::cout << part1 << std::endl;
    std::cout << part2 << std::endl;
  return 0;
}