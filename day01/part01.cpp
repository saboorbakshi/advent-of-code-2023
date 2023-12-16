#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    ifstream inputFile("input.txt");

    if (!inputFile.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    int sum = 0;
    string line, c;

    while (getline(inputFile, line)) {

        int len = line.length();

        for (int i = 0; i < len; ++i) {
            if (isdigit(line[i])) {
                c = line[i];               
                break;
            }
        }
        
        for (int i = len - 1; i >= 0; --i) {
            if (isdigit(line[i])) {
                c += line[i];             
                break;
            }
        }

        int x = stoi(c);

        sum += x;
    }

    inputFile.close();

    cout << sum << endl;

    return 0;
}