#include <bits/stdc++.h>
using namespace std;

/*
Merge Sort (Bottom-Up) - Algoritmo de Divisão e Conquista

Funcionamento:
- Implementação iterativa (bottom-up) do Merge Sort
- Começa mesclando subarrays de tamanho 1
- Dobra o tamanho dos subarrays a cada iteração
- Combina os pares de subarrays ordenados até ordenar todo o array


Complexidade:
- Tempo: O(n log n)
- Espaço: O(n)
*/

void merge(vector<int>& arr, int inicio, int meio, int fim) {
    vector<int> temp(fim - inicio + 1);
    int i = inicio, j = meio + 1, k = 0;
    
    while (i <= meio && j <= fim) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    
    while (i <= meio) {
        temp[k++] = arr[i++];
    }
    
    while (j <= fim) {
        temp[k++] = arr[j++];
    }
    
    for (i = 0; i < k; i++) {
        arr[inicio + i] = temp[i];
    }
}

void mergeSort(vector<int>& arr) {
    int n = arr.size();
    

    for (int tamanho = 1; tamanho < n; tamanho = 2 * tamanho) {
       
        for (int inicio = 0; inicio < n - 1; inicio += 2 * tamanho) {
            int meio = min(inicio + tamanho - 1, n - 1);
            int fim = min(inicio + 2 * tamanho - 1, n - 1);
            
          
            merge(arr, inicio, meio, fim);
        }
    }
}

int main(){

    vector<int> array = {18, 12, 17, 20, 27, 4, 0};

     cout << "Array sem ordernar:" << endl;
     
     for(auto v : array){
        cout << v << " "; 
         
    }

    cout << endl;
    
    mergeSort(array);
    
    cout << "Array ordernado:" << endl ;

    for(auto v : array){
        cout << v << " ";  
    }

    return 0;
}