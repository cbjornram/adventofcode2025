#include <iostream>
#include <fstream>
#include <string>

int main() {

    int dial = 50;
    int count = 0;

    std::ifstream file("input.txt");
    std::string str;
    while (std::getline(file, str))
    {
        if (str.find("L") != std::string::npos) {
            str.erase(0,1);
            dial = dial - stoi(str);
        } else if (str.find("R") != std::string::npos) {
            str.erase(0,1);
            dial = dial + stoi(str);
        }

        while (dial < 0) {
            dial = dial + 100;
        }
        while (dial > 99) {
            dial = dial - 100;
        }

        if (dial == 0) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}