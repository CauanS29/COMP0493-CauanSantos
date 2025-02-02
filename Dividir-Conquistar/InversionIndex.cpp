#include <bits/stdc++.h>
using namespace std;

/*
Inversion Index (Contagem de Inversões) - Algoritmo de Divisão e Conquista

Funcionamento:
- Usa uma modificação do Merge Sort para contar inversões
- Uma inversão ocorre quando i < j e arr[i] > arr[j]
- Divide o array em duas metades
- Conta inversões em cada metade recursivamente
- Combina e conta inversões entre as duas metades durante o merge

Melhor usado quando:
- É necessário contar quantos pares de elementos estão fora de ordem
- O array é grande e precisa de uma solução eficiente
- Útil em análise de desordem em sequências

Complexidade:
- Tempo: O(n log n)
- Espaço: O(n)
*/

long long mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    long long inversions = 0;
    
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            inversions += mid - i + 1;
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    
    for (int i = 0; i < k; i++) {
        arr[left + i] = temp[i];
    }
    
    return inversions;
}

long long countInversions(vector<int>& arr, int left, int right) {
    long long inversions = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        inversions += countInversions(arr, left, mid);
        inversions += countInversions(arr, mid + 1, right);
        inversions += mergeAndCount(arr, left, mid, right);
    }
    return inversions;
}

void printArray(const vector<int>& arr, const string& mensagem) {
    cout << mensagem << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr1 = {8, 4, 2, 1};
    printArray(arr1, "Array 1");
    cout << "Número de inversões: " << countInversions(arr1, 0, arr1.size() - 1) << "\n\n";
    
    vector<int> arr2 = {3, 1, 2};
    printArray(arr2, "Array 2");
    cout << "Número de inversões: " << countInversions(arr2, 0, arr2.size() - 1) << "\n\n";
    
    vector<int> arr3 = {1, 2, 3, 4};
    printArray(arr3, "Array 3");
    cout << "Número de inversões: " << countInversions(arr3, 0, arr3.size() - 1) << "\n";
    
    return 0;
}
