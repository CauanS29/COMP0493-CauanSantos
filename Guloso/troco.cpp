#include <bits/stdc++.h>
using namespace std;

/*
Problema do Troco - Algoritmo Guloso

Funcionamento:
- Recebe um valor e um conjunto de moedas disponíveis
- Sempre escolhe a maior moeda possível que não ultrapasse o valor restante
- Repete o processo até que o valor restante seja zero

Melhor usado quando:
- O sistema monetário é canônico (moedas maiores são múltiplos das menores)
- Precisamos minimizar o número de moedas no troco
- Queremos uma solução rápida e simples

Complexidade:
- Tempo: O(n) onde n é o número de tipos de moedas
- Espaço: O(1)
*/

vector<int> calcularTroco(vector<int>& moedas, int valor) {
    vector<int> resultado(moedas.size(), 0);
    int valorRestante = valor;
    
    for (int i = 0; i < moedas.size(); i++) {
        while (valorRestante >= moedas[i]) {
            resultado[i]++;
            valorRestante -= moedas[i];
        }
    }
    
    return resultado;
}

void imprimirTroco(const vector<int>& moedas, const vector<int>& quantidades) {
    cout << "Troco:\n";
    for (int i = 0; i < moedas.size(); i++) {
        if (quantidades[i] > 0) {
            cout << quantidades[i] << " moeda(s) de " << moedas[i] << " centavos\n";
        }
    }
}

int main() {
    vector<int> moedas = {100, 50, 25, 10, 5, 1};  
    
    int valor;
    cout << "Digite o valor do troco em centavos: ";
    cin >> valor;
    
    vector<int> resultado = calcularTroco(moedas, valor);
    imprimirTroco(moedas, resultado);
    
    return 0;
}
