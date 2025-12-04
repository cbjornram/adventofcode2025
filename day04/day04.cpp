#include <iostream>
#include <fstream>
#include <string>

int main() {
    long count = 0;

    std::ifstream file("input.txt");
    std::string str0;
    std::string str1;
    std::string str2;
    bool oneMoreLine = true;
    while (std::getline(file, str2) || oneMoreLine)
    {
        if (str1.empty()) {
            str1 = str2;
            std::getline(file, str2);
        } else if (str2.empty()) {
            oneMoreLine = false;
        }

        int rollCount = 0;

        for (int pos = 0; pos < str1.length(); pos++) {
            if (str1[pos] == '@') {
                if (pos > 0) {
                    if (str1[pos - 1] == '@') {
                        rollCount++;
                    }
                    if (oneMoreLine && str2[pos - 1] == '@') {
                        rollCount++;
                    }
                    if (!str0.empty() && str0[pos - 1] == '@') {
                        rollCount++;
                    }
                }
                if (pos < str1.length()) {
                    if (str1[pos + 1] == '@') {
                        rollCount++;
                    }
                    if (oneMoreLine && str2[pos + 1] == '@') {
                        rollCount++;
                    }
                    if (!str0.empty() && str0[pos + 1] == '@') {
                        rollCount++;
                    }
                }
                if (oneMoreLine && str2[pos] == '@') {
                    rollCount++;
                }
                if (!str0.empty() && str0[pos] == '@') {
                    rollCount++;
                }
                if (rollCount < 4) {
                    count++;
                }
                rollCount = 0;
            }
        }
        str0 = str1;
        str1 = str2;
    }
    std::cout << count << std::endl;
    return 0;
}