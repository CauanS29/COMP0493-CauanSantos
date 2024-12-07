#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream file("exemplo.txt");
    string line, T, lastLine;
    bool stopReading = false;

    while (getline(file, line)) {
        if (line.substr(0, 7) == ".......") {
            stopReading = true;
            lastLine = line;
            break;
        }
        if (!T.empty()) T += " ";
        T += line;
    }

    cout << "String combinada (T): " << T << endl;
    cout << "Última linha: " << lastLine << endl;
    file.close();
    return 0;
}
