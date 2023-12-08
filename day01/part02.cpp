#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    std::ifstream inputFile("tinput.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; // Return an error code
    }

    int y = 0;

    // Read the file line by line
    std::string line;
    while (std::getline(inputFile, line)) {

        cout << line << endl;

        string s;

        string digits[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

        int end = -1;
        int start = line.length();

        int endDigit;
        int startDigit;

        for (int i = 0; i < 9; ++i) {
            int first = line.find(digits[i]);
            int last = line.rfind(digits[i]);

            if (first != string::npos && first < start) {
                start = first;
                startDigit = i + 1;
            }

            if (last != string::npos && last > end) {
                end = last;
                endDigit = i + 1;
            }
        }

        cout << start << " " << startDigit << " " << end << " " << endDigit;

        string strStart = digits[startDigit - 1];
        if (start != line.length()) {
            line.replace(start, strStart.length(), to_string(startDigit));
            end -= strStart.length() - 1;
        }

        string strEnd = digits[endDigit - 1];
        if (end >= 0 && line[end] == strEnd[0]) line.replace(end, strEnd.length(), to_string(endDigit)); 

        int k = line.length();

        for (int i = 0; i < k; ++i) {
            if (isdigit(line[i])) {
                s = line[i];               
                break;
            }
        }
        
        for (int i = k - 1; i >= 0; --i) {
            if (isdigit(line[i])) {
                s += line[i];             
                break;
            }
        }

        int x = stoi(s);

        cout << x << endl;

        y += x;
    }

    // Close the file
    inputFile.close();

    cout << y << endl;

    return 0; // Return 0 to indicate success
}