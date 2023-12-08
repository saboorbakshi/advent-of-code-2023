#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    std::ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; 
    }

    int sum = 0;

    std::string line;

    while (std::getline(inputFile, line)) {

        string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        int endIndex = -1;
        int startIndex = line.length();

        int endDigit;
        int startDigit;

        for (int i = 0; i < 9; ++i) {
            int first = line.find(digits[i]);
            int last = line.rfind(digits[i]);

            if (first != string::npos && first < startIndex) {
                startIndex = first;
                startDigit = i + 1;
            }

            if (last != string::npos && last > endIndex) {
                endIndex = last;
                endDigit = i + 1;
            }
        }

        size_t first = line.find_first_of("123456789");
        size_t last = line.find_last_of("123456789");

        string c;

        if (startIndex < (int) first) {
            c = to_string(startDigit);
        } else {
            c = line[first];
        }

        if (endIndex > (int) last) {
            c += to_string(endDigit);
        } else {
            c += line[last];
        }

        int x = stoi(c);

        sum += x;
    }

    inputFile.close();

    cout << sum << endl;

    return 0;
}