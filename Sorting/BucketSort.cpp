#include <bits/stdc++.h>
using namespace std;

/*
Bucket Sort - Algoritmo de ordenação por distribuição

Funcionamento:
- Divide os elementos em 'baldes' baseado em seus valores
- Ordena cada balde individualmente
- Concatena os baldes para obter o array ordenado

Melhor usado quando:
- Os dados estão uniformemente distribuídos
- O intervalo dos valores é conhecido
- Há memória disponível para os baldes

Complexidade:
- Média: O(n + k) onde n é o número de elementos e k é o número de baldes
- Pior caso: O(n²) quando muitos elementos caem no mesmo balde
*/


void bucketSort(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());

    int n = arr.size();
    vector<vector<int>> buckets(n);

    for (int i = 0; i < n; i++) {
        int bucket_idx = (int)((arr[i] - min_val) * (n - 1) / (max_val - min_val));
        buckets[bucket_idx].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(buckets[i].begin(), buckets[i].end());
    }

    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int num : buckets[i]) {
            arr[index++] = num;
        }
    }
}

template<typename T>
void printArray(const vector<T>& arr, const string& mensagem) {
    cout << mensagem << ": ";
    for (const T& num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    
    vector<int> arr_int = {64, 34, 25, 12, 22, 11, 90};
    printArray(arr_int, "Array int original");
    bucketSort(arr_int);
    printArray(arr_int, "Array int ordenado");
    
    return 0;
}