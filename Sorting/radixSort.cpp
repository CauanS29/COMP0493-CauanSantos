#include <bits/stdc++.h>
using namespace std;

/*
Radix Sort - Algoritmo de ordenação não comparativo

Funcionamento:
- Ordena os números dígito por dígito, da posição menos significativa para a mais significativa
- Usa Counting Sort como sub-rotina para ordenar cada dígito
- Mantém a ordem relativa dos elementos com o mesmo valor do dígito (estável)

Melhor usado quando:
- Os números têm quantidade fixa de dígitos
- É necessário ordenar inteiros em base específica
- A estabilidade é importante
- Os números não são muito grandes

Complexidade:
- Tempo: O(d * (n + k)) onde:
  * d é o número de dígitos do maior número
  * n é a quantidade de números
  * k é a base numérica (10 para decimal)
- Espaço: O(n + k)
*/

void countingSort(vector<int>& arr, int exp) {
    vector<int> output(arr.size());
    vector<int> count(10, 0);
    
    for (int num : arr) {
        count[(num / exp) % 10]++;
    }
    
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    arr = output;
}

void radixSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int max_val = *max_element(arr.begin(), arr.end());
    
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSort(arr, exp);
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
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    printArray(arr, "Array original");
    radixSort(arr);
    printArray(arr, "Array ordenado");
    
    return 0;
}