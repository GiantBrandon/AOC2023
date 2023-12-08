#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>
#include <numeric>

int main() {
    long part1 = LONG_MAX;
    long part2 = LONG_MAX;
    std::string line;
    std::ifstream file("day5.txt");
    std::vector<std::string> lines;
    
    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    struct translation {
        long source;
        long destination;
        long range;
    };

    std::vector<long> seeds;
    std::vector<std::vector<translation> > translations;

    for (int i = 0; i < lines.size(); i++) {
        std::string current = lines[i];
        if (i == 0) {
            std::stringstream stream(current);
            std::string intro;
            stream >> intro;

            std::string token;
            while (stream >> token) {
                seeds.push_back(std::stol(token));
            }
        } else if (current == "") {
            std::vector<translation> newTranslation;
            translations.push_back(newTranslation);
        } else if (!isdigit(current[0])) {
        } else {
            std::stringstream stream(current);
            std::string destination, source, range;
            stream >> destination >> source >> range;
            translation t = {
                std::stol(source),
                std::stol(destination),
                std::stol(range),
            };
            translations[translations.size() - 1].push_back(t);
        }
    }

    for (long seed : seeds) {
        long value = seed;
        for (std::vector<translation> row : translations) {
            for(translation t : row) {
                if (t.source <= value && t.source + t.range - 1 >= value) {
                    value = value + t.destination - t.source;
                    break;
                }
            }
        }
        if (value < part1) {
            part1 = value;
        }
    }

    for (long location = 0; location < LONG_MAX; location++) {
        long value = location;
        for (int i = translations.size(); i >= 0; i--) {
            std::vector<translation> row = translations[i];
            for(translation t : row) {
                if (t.destination <= value && t.destination + t.range - 1 >= value) {
                    value = value - (t.destination - t.source);
                    break;
                }
            }
        }

        bool found = false;
        for(int i = 0; i < seeds.size(); i += 2) {
            long min = seeds[i];
            long max = seeds[i] + seeds[i + 1];
            if (value >= min && value <= max) {
                part2 = location;
                found = true;
                break;
            }
        }
        if (found)
            break;
    }
    
    std::cout << part1 << std::endl;
    std::cout << part2 << std::endl;
  return 0;
}