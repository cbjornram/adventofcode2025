#include <iostream>
#include <fstream>
#include <string>

int main() {

    long count = 0;
    std::vector<std::string> lowerRanges;
    std::vector<std::string> upperRanges;

    std::ifstream file("input.txt");
    std::string str1;
    while (std::getline(file, str1) && !str1.empty())
    {
        std::string delimiter = "-";
        std::string str0 = str1.substr(0, str1.find(delimiter));
        str1.erase(0, str1.find(delimiter) + delimiter.length());

        lowerRanges.push_back(str0);
        upperRanges.push_back(str1);
    }

    while (std::getline(file, str1))
    {
        for (int i = 0; i < lowerRanges.size(); ++i) {
            if (stol(lowerRanges[i]) < stol(str1) && stol(str1) < stol(upperRanges[i])) {
                count++;
                break;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}