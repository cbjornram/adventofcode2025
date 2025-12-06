#include <iostream>
#include <fstream>
#include <string>

std::vector<std::string> split(std::string& s, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
        s.erase(0, s.find_first_not_of(' '));
    }
    tokens.push_back(s);

    return tokens;
}

int main() {

    long count = 0;
    std::vector<std::vector<std::string>> numbers;

    std::ifstream file("input.txt");
    std::string str;
    while (std::getline(file, str))
    {
        numbers.push_back(split(str, " "));
    }

    for (int i = 0; i < numbers[0].size(); ++i) {
        if (numbers[4][i] == "*") {
            count = count + stol(numbers[0][i]) * stol(numbers[1][i]) * stol(numbers[2][i]) * stol(numbers[3][i]);
        } else if (numbers[4][i] == "+") {
            count = count + stol(numbers[0][i]) + stol(numbers[1][i]) + stol(numbers[2][i]) + stol(numbers[3][i]);
        }
    }

    std::cout << count << std::endl;
    return 0;
}