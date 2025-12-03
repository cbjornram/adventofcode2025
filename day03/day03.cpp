#include <iostream>
#include <fstream>
#include <string>

int main() {

    long count = 0;

    std::ifstream file("input.txt");
    std::string str;
    while (std::getline(file, str))
    {
        std::string strCheck = str;
        int first = 0;
        int second = 0;

        for (int i = 9; i >= 0; i--) {
            while (str.find(std::to_string(i)) != std::string::npos) {
                std::size_t pos = str.find(std::to_string(i));
                if (first == 0 && pos != std::string::npos) {
                    if (pos == 99) {
                        second = i;
                        i--;
                        continue;
                    }
                    first = i;
                    str.erase(str.begin(), str.begin()+pos+1);
                } else if (second == 0 && pos != std::string::npos) {
                    second = i;
                    break;
                }
                if (first != 0 && second != 0) {
                    break;
                }
            }
            if (first != 0 && second != 0) {
                break;
            }
        }
        count = count + first*10 + second;
    }
    std::cout << count << std::endl;
    return 0;
}