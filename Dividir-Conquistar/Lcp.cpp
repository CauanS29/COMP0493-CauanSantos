#include <bits/stdc++.h>
using namespace std;

/*
Longest Common Prefix (LCP) - Algoritmo de Divisão e Conquista

Funcionamento:
- Divide o array de strings em duas metades
- Encontra o LCP recursivamente para cada metade
- Combina os resultados encontrando o prefixo comum entre os LCPs das duas metades

Melhor usado quando:
- É necessário encontrar o maior prefixo comum entre várias strings
- A quantidade de strings é grande
- As strings podem ter tamanhos diferentes

Complexidade:
- Tempo: O(S * log n) onde:
  * S é o comprimento da menor string
  * n é o número de strings
- Espaço: O(log n) devido à pilha de recursão
*/

string findLCPPair(const string& str1, const string& str2) {
    int minLen = min(str1.length(), str2.length());
    for (int i = 0; i < minLen; i++) {
        if (str1[i] != str2[i]) {
            return str1.substr(0, i);
        }
    }
    return str1.substr(0, minLen);
}

string findLCPUtil(const vector<string>& arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }
    
    if (end - start == 1) {
        return findLCPPair(arr[start], arr[end]);
    }
    
    int mid = (start + end) / 2;
    string leftLCP = findLCPUtil(arr, start, mid);
    string rightLCP = findLCPUtil(arr, mid + 1, end);
    
    return findLCPPair(leftLCP, rightLCP);
}

string findLCP(const vector<string>& arr) {
    if (arr.empty()) return "";
    if (arr.size() == 1) return arr[0];
    
    return findLCPUtil(arr, 0, arr.size() - 1);
}

int main() {
    vector<string> arr1 = {"flor", "flores", "floresta", "florescer"};
    cout << "Array 1: ";
    for (const string& s : arr1) cout << s << " ";
    cout << "\nLCP: " << findLCP(arr1) << "\n\n";
    
    vector<string> arr2 = {"cachorro", "cacho", "cachimbo", "cachoeira"};
    cout << "Array 2: ";
    for (const string& s : arr2) cout << s << " ";
    cout << "\nLCP: " << findLCP(arr2) << "\n\n";
    
    vector<string> arr3 = {"python", "java", "javascript"};
    cout << "Array 3: ";
    for (const string& s : arr3) cout << s << " ";
    cout << "\nLCP: " << findLCP(arr3) << "\n";
    
    return 0;
}
