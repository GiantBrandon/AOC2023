#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <map>
#include <set>

bool check(std::vector<std::string> lines, int row, int column) {
    if (row >= 0 && row < lines.size() && column >= 0 && column < lines.size()) {
        char c = lines[row][column];
        return !isdigit(c) && c != '.';
    }
    return false;
}
bool check2(std::vector<std::string> lines, int row, int column) {
    if (row >= 0 && row < lines.size() && column >= 0 && column < lines.size()) {
        return lines[row][column] == '*';
    }
    return false;
}

int main() {
    int part1 = 0;
    int part2 = 0;
    std::vector<std::string> lines;
    std::string line;
    std::ifstream file("day3.txt");
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            bool isValid = false;
            int total = 0;
            while (isdigit(lines[i][j])) {
                total *= 10;
                total += lines[i][j] - '0';
                if (!isValid) {
                    isValid = check(lines, i - 1, j - 1) || check(lines, i - 1, j) || check(lines, i - 1, j + 1) ||
                    check(lines, i, j - 1) || check(lines, i, j + 1) ||
                    check(lines, i + 1, j - 1) || check(lines, i + 1, j) || check(lines, i + 1, j + 1);
                }
                j++;
            }
            if (isValid) {
                part1 += total;
            }
        }
    }
    std::map<std::pair<int, int>, std::pair<int, int> > asteriskCoordinate_countTotal;
    for (int i = 0; i < lines.size(); i++) {
        for (int j = 0; j < lines[i].size(); j++) {
            std::set<std::pair<int, int> > asterisks;
            int total = 0;
            while (isdigit(lines[i][j])) {
                total *= 10;
                total += lines[i][j] - '0';
                if (check2(lines, i - 1, j - 1))
                    asterisks.insert(std::pair<int, int>(i - 1, j - 1));
                if (check2(lines, i - 1, j))
                    asterisks.insert(std::pair<int, int>(i - 1, j));
                if (check2(lines, i - 1, j + 1))
                    asterisks.insert(std::pair<int, int>(i - 1, j + 1));
                if (check2(lines, i, j - 1))
                    asterisks.insert(std::pair<int, int>(i, j - 1));
                if (check2(lines, i, j + 1))
                    asterisks.insert(std::pair<int, int>(i, j + 1));
                if (check2(lines, i + 1, j - 1))
                    asterisks.insert(std::pair<int, int>(i + 1, j - 1));
                if (check2(lines, i + 1, j))
                    asterisks.insert(std::pair<int, int>(i + 1, j));
                if (check2(lines, i + 1, j + 1))
                    asterisks.insert(std::pair<int, int>(i + 1, j + 1));
                j++;
            }
            for (std::pair<int, int> asterisk : asterisks) {
                if(asteriskCoordinate_countTotal.count(asterisk) == 0) {
                    asteriskCoordinate_countTotal[asterisk] = std::pair<int, int>(1, total);
                } else {
                    std::pair<int, int> previous = asteriskCoordinate_countTotal[asterisk];
                    asteriskCoordinate_countTotal[asterisk] = std::pair<int, int>(previous.first + 1, previous.second * total);
                }
            }
        }
    }
    for (const auto& [key, value] : asteriskCoordinate_countTotal) {
        if (value.first == 2) {
            part2 += value.second;
        }
    }
    std::cout << part1 << std::endl;
    std::cout << part2 << std::endl;
  return 0;
}