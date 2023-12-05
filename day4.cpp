#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <numeric>

int main() {
    int part1 = 0;
    int part2 = 0;
    std::string line;
    std::ifstream file("day4.txt");
    enum State { LUCKY_NUMBERS, MY_NUMBERS };
    std::vector<int> matches(209, 0);
    int index = 0;
    
    while (std::getline(file, line))
    {
        State state = LUCKY_NUMBERS;
        std::vector<int> luckyNumbers;
        int count = 0;

        std::stringstream stream(line);
        std::string card, cardNumber;
        stream >> card;
        stream >> cardNumber;

        std::string token;
        while (stream >> token) {
            if (token == "|") {
                state = MY_NUMBERS;
            } else {
                int number = std::stoi(token);
                if (state == LUCKY_NUMBERS) {
                    luckyNumbers.push_back(number);
                } else {
                    if (std::find(luckyNumbers.begin(), luckyNumbers.end(), number) != luckyNumbers.end()) {
                        count++;
                    }
                }
            }
        }
        if (count > 0) {
            part1 += pow(2, count - 1);
            matches[index] = count;
        }
        index++;
    }

    std::vector<int> cards(209, 1);
    index = 0;
    for (int match: matches) {
        for(int i = index + 1; i <= index + match; i++) {
            cards[i] += cards[index];
        }
        part2 += cards[index];
        index++;
    }
    std::cout << part1 << std::endl;
    std::cout << part2 << std::endl;
  return 0;
}