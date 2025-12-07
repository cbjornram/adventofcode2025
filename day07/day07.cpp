#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <set>

int main() {

    long count = 0;
    std::set<unsigned long> positions;

    std::ifstream file("input.txt");
    std::string str;
    while (std::getline(file, str))
    {
        if (positions.empty()) {
            unsigned long pos = str.find('S');
            positions.insert(pos);
            continue;
        }

        std::set<unsigned long> newPositions;
        std::set<unsigned long> toErase;

        for (unsigned long pos : positions) {
            if (str[pos] == '^') {
                count++;
                toErase.insert(pos);
                newPositions.insert(pos-1);
                newPositions.insert(pos+1);
            }
        }
        for (unsigned long pos : toErase) {
            positions.erase(pos);
        }
        if (!newPositions.empty()) {
            positions.insert(newPositions.begin(), newPositions.end());
        }
    }

    std::cout << count << std::endl;
    return 0;
}
