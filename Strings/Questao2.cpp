#include <bits/stdc++.h>
using namespace std;

vector<int> encontraOcorrencia(const string& T, const string& P) {
    vector<int> indices;
    size_t pos = T.find(P, 0);
    while (pos != string::npos) {
        indices.push_back(pos);
        pos = T.find(P, pos + 1);
    }
    if (indices.empty()) indices.push_back(-1);
    return indices;
}

int main() {
    string T = "I love CS3233 Competitive Programming. i also love AlGoRiThM";
    string P = "love";
    vector<int> indices = encontraOcorrencia(T, P);

    cout << "Índices: ";
    for (int index : indices) cout << index << " ";
    cout << endl;
    return 0;
}
