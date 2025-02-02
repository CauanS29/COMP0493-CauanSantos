#include <bits/stdc++.h>
using namespace std;

/*
Counting Sort - Algoritmo de ordenação por contagem

Funcionamento:
- Conta a frequência de cada elemento no array
- Calcula as posições finais de cada elemento
- Constrói o array ordenado usando as contagens

Melhor usado quando:
- Os elementos são inteiros
- O intervalo dos valores é pequeno em relação ao tamanho do array
- É necessária estabilidade na ordenação

Complexidade:
- Tempo: O(n + k) onde n é o número de elementos e k é o intervalo dos valores
- Espaço: O(k) para o array de contagem

Limitações:
- Funciona apenas com números inteiros não negativos
- Ineficiente quando o intervalo de valores é muito grande
*/

void countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int max_val = *max_element(arr.begin(), arr.end());
    vector<int> count(max_val + 1, 0);
    
    for (int num : arr) {
        count[num]++;
    }
    
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (count[i] > 0) {
            arr[index++] = i;
            count[i]--;
        }
    }
}

void printArray(const vector<int>& arr, const string& mensagem) {
    cout << mensagem << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    printArray(arr, "Array original");
    countingSort(arr);
    printArray(arr, "Array ordenado");
    
    return 0;
}