#include <bits/stdc++.h>
using namespace std;

/*
Busca em Profundidade (DFS) em Matriz de Adjacência - Algoritmo de Grafos

Funcionamento:
- Explora o grafo indo o mais fundo possível em cada ramo
- Usa recursão ou pilha para processar os vértices
- Marca os vértices visitados para evitar ciclos
- Retrocede quando encontra um beco sem saída

Melhor usado quando:
- Precisamos encontrar componentes fortemente conexos
- Queremos detectar ciclos no grafo
- Necessitamos gerar uma ordenação topológica
- Precisamos resolver problemas de labirinto

Complexidade:
- Tempo: O(V²) onde V é o número de vértices
- Espaço: O(V) para a pilha de recursão e vetor de visitados
*/

void dfs(vector<vector<int>>& grafo, vector<bool>& visitado, vector<int>& tempo_descoberta, 
         vector<int>& tempo_finalizacao, int vertice, int& tempo) {
    
    visitado[vertice] = true;
    tempo_descoberta[vertice] = ++tempo;
    cout << vertice << " ";
    
    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[vertice][i] && !visitado[i]) {
            dfs(grafo, visitado, tempo_descoberta, tempo_finalizacao, i, tempo);
        }
    }
    
    tempo_finalizacao[vertice] = ++tempo;
}

void executarDFS(vector<vector<int>>& grafo, int inicio) {
    int n = grafo.size();
    vector<bool> visitado(n, false);
    vector<int> tempo_descoberta(n, 0);
    vector<int> tempo_finalizacao(n, 0);
    int tempo = 0;
    
    cout << "Ordem de visitação: ";
    dfs(grafo, visitado, tempo_descoberta, tempo_finalizacao, inicio, tempo);
    cout << "\n\n";
    
    cout << "Tempos de descoberta e finalização:\n";
    for (int i = 0; i < n; i++) {
        cout << "Vértice " << i << ": descoberta = " << tempo_descoberta[i] 
             << ", finalização = " << tempo_finalizacao[i] << "\n";
    }
}

int main() {
    int n = 6;
    vector<vector<int>> grafo(n, vector<int>(n, 0));
    
    grafo[0][1] = grafo[1][0] = 1;
    grafo[0][2] = grafo[2][0] = 1;
    grafo[1][3] = grafo[3][1] = 1;
    grafo[2][3] = grafo[3][2] = 1;
    grafo[3][4] = grafo[4][3] = 1;
    grafo[4][5] = grafo[5][4] = 1;
    
    cout << "Matriz de adjacência do grafo:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << grafo[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    int verticeInicial = 0;
    cout << "Iniciando DFS a partir do vértice " << verticeInicial << "\n\n";
    
    executarDFS(grafo, verticeInicial);
    
    return 0;
}