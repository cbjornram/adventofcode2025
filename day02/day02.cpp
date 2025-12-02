#include <iostream>
#include <fstream>
#include <string>

int main() {

    long count = 0;

    std::ifstream file("input.txt");
    std::string str1;
    while (std::getline(file, str1, ','))
    {
        std::string delimiter = "-";
        std::string str0 = str1.substr(0, str1.find(delimiter));
        str1.erase(0, str1.find(delimiter) + delimiter.length());

        long lower = stol(str0);
        long upper = stol(str1);

        while (lower <= upper) {
            std::string half = std::to_string(lower).substr(0, std::to_string(lower).length()/2);
            std::string otherHalf = std::to_string(lower).substr(std::to_string(lower).length()/2);
            if (half == otherHalf) {
                count = count + lower;
            }
            lower++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}