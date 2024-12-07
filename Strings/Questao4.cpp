#include <bits/stdc++.h>
using namespace std;

vector<string> tokenizeString(const string& T) {
    vector<string> tokens;
    string token;
    istringstream stream(T);
    while (getline(stream, token, ' ')) {
        size_t pos;
        while ((pos = token.find('.')) != string::npos)
            token.erase(pos, 1);
        if (!token.empty()) tokens.push_back(token);
    }
    return tokens;
}

int main() {
    string T = "I love CS3233 Competitive Programming. i also love AlGoRiThM.";
    vector<string> tokens = tokenizeString(T);

    cout << "Tokens:\n";
    for (const string& t : tokens) cout << t << " ";

    sort(tokens.begin(), tokens.end());
    cout << "\nTokens ordenados:\n";
    for (const string& t : tokens) cout << t << " ";
    cout << endl;

    return 0;
}
