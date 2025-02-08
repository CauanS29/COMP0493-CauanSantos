#include <bits/stdc++.h>
using namespace std;

/*
Escalonamento de Tarefas - Algoritmo Guloso

Funcionamento:
- Ordena as tarefas por tempo de início
- Atribui cada tarefa à primeira máquina disponível
- Se nenhuma máquina estiver disponível, cria uma nova
- Minimiza o número de máquinas necessárias

Melhor usado quando:
- Temos tarefas com tempo de início e fim definidos
- Precisamos alocar recursos (máquinas) de forma eficiente
- Queremos minimizar o número de recursos utilizados

Complexidade:
- Tempo: O(n log n) devido à ordenação
- Espaço: O(n)
*/

struct Tarefa {
    int id;
    int inicio;
    int fim;
};

bool compararTarefas(const Tarefa& a, const Tarefa& b) {
    return a.inicio < b.inicio;
}

void escalonarTarefas(vector<Tarefa>& tarefas) {
    sort(tarefas.begin(), tarefas.end(), compararTarefas);
    
    vector<int> maquinas;  
    vector<int> alocacao(tarefas.size());  
    
    for (int i = 0; i < tarefas.size(); i++) {
        bool alocada = false;
        
       
        for (int j = 0; j < maquinas.size(); j++) {
            if (maquinas[j] <= tarefas[i].inicio) {
                maquinas[j] = tarefas[i].fim;
                alocacao[i] = j + 1;
                alocada = true;
                break;
            }
        }
        
        
        if (!alocada) {
            maquinas.push_back(tarefas[i].fim);
            alocacao[i] = maquinas.size();
        }
    }
    
    cout << "Número total de máquinas necessárias: " << maquinas.size() << "\n\n";
    cout << "Alocação das tarefas:\n";
    for (int i = 0; i < tarefas.size(); i++) {
        cout << "Tarefa " << tarefas[i].id << " (início: " << tarefas[i].inicio 
             << ", fim: " << tarefas[i].fim << ") -> Máquina " << alocacao[i] << "\n";
    }
}

int main() {
    vector<Tarefa> tarefas = {
        {1, 2, 5},     
        {2, 1, 3},
        {3, 4, 7},
        {4, 1, 4},
        {5, 5, 8}
    };
    
    cout << "Tarefas a serem escalonadas:\n";
    for (const auto& tarefa : tarefas) {
        cout << "Tarefa " << tarefa.id << ": início = " << tarefa.inicio 
             << ", fim = " << tarefa.fim << "\n";
    }
    cout << "\n";
    
    escalonarTarefas(tarefas);
    
    return 0;
}
