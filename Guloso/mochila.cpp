#include <bits/stdc++.h>
using namespace std;

/*
Problema da Mochila Fracionária - Algoritmo Guloso

Funcionamento:
- Ordena os itens por valor/peso (densidade de valor)
- Seleciona os melhores itens primeiro
- Permite frações de itens
- Maximiza o valor total respeitando o limite de peso

Melhor usado quando:
- Os itens podem ser divididos (líquidos, minerais, etc)
- Precisamos maximizar o valor total
- A solução ótima local leva à solução ótima global

Complexidade:
- Tempo: O(n log n) devido à ordenação
- Espaço: O(n)
*/

struct Item {
    int id;
    double peso;
    double valor;
    double razao;  
};

bool compararItens(Item a, Item b) {
    return a.razao > b.razao;
}

double mochilaFracionaria(vector<Item>& itens, double capacidade) {
    for (auto& item : itens) {
        item.razao = item.valor / item.peso;
    }
    
    sort(itens.begin(), itens.end(), compararItens);
    
    double valorTotal = 0.0;
    double pesoAtual = 0.0;
    vector<pair<int, double>> selecao;  
    
    for (const auto& item : itens) {
        if (pesoAtual + item.peso <= capacidade) {
            valorTotal += item.valor;
            pesoAtual += item.peso;
            selecao.push_back({item.id, 1.0});
        } else {
            double espacoRestante = capacidade - pesoAtual;
            double fracao = espacoRestante / item.peso;
            valorTotal += item.valor * fracao;
            selecao.push_back({item.id, fracao});
            break;
        }
    }
    
    cout << "Itens selecionados:\n";
    for (const auto& sel : selecao) {
        cout << "Item " << sel.first << ": " 
             << fixed << setprecision(2) << sel.second * 100 
             << "% utilizado\n";
    }
    
    return valorTotal;
}

int main() {
    vector<Item> itens = {
        {1, 10, 60},    
        {2, 20, 100},
        {3, 30, 120}
    };
    
    double capacidade = 50;
    
    cout << "Capacidade da mochila: " << capacidade << "\n\n";
    cout << "Itens disponíveis:\n";
    for (const auto& item : itens) {
        cout << "Item " << item.id << ": peso = " << item.peso 
             << ", valor = " << item.valor << "\n";
    }
    cout << "\n";
    
    double valorMaximo = mochilaFracionaria(itens, capacidade);
    cout << "\nValor total obtido: " << fixed << setprecision(2) << valorMaximo << "\n";
    
    return 0;
}
