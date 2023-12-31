#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {

    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);

    int sum = 0;
    string line;

    while (getline(file, line)) {

        stringstream ss(line);
        
        string color, gameID;
        bool flag = true;
        int num;

        ss >> gameID >> gameID;

        gameID.pop_back();

        while (!ss.eof()) {

            ss >> num >> color;

            color.pop_back();

            if (color[0] == 'r' && num > 12 ||
                color[0] == 'g' && num > 13 ||
                color[0] == 'b' && num > 14) {
                flag = false;
                break;
            }
        }
        if (flag) sum += stoi(gameID);
    }

    cout << sum << endl;

    return 0;
}
