#include <bits/stdc++.h>
using namespace std;

string maisFrequente(const vector<string>& tokens) {
    map<string, int> freq;
    for (const string& token : tokens) freq[token]++;
    int maxCount = 0;
    string mostFrequent;
    for (const auto& [word, count] : freq) {
        if (count > maxCount) {
            maxCount = count;
            mostFrequent = word;
        }
    }
    return mostFrequent;
}

int main() {
    vector<string> tokens = {"i", "love", "cs3233", "competitive", "programming", "i", "also", "love", "algorithm"};
    cout << "Palavra mais frequente: " << maisFrequente(tokens) << endl;
    return 0;
}
