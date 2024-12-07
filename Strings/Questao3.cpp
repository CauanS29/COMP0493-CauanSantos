#include <bits/stdc++.h>
using namespace std;

void analisa(const string& T) {
    int vogais = 0, consoantes = 0, digitos = 0;
    for (char c : T) {
        if (isdigit(c)) digitos++;
        else if (isalpha(c)) {
            c = tolower(c);
            if (string("aeiou").find(c) != string::npos)
                vogais++;
            else
                consoantes++;
        }
    }
    cout << "Vogais: " << vogais << ", Consoantes: " << consoantes << ", Dígitos: " << digitos << endl;
}

int main() {
    string T = "I love CS3233 Competitive Programming. i also love AlGoRiThM";
    analisa(T);
    return 0;
}
