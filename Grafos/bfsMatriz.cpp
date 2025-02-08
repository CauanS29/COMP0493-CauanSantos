#include <bits/stdc++.h>
using namespace std;

/*
Busca em Largura (BFS) em Matriz de Adjacência - Algoritmo de Grafos

Funcionamento:
- Visita todos os vértices de um grafo nível por nível
- Usa uma fila para processar os vértices
- Marca os vértices visitados para evitar ciclos
- Explora primeiro todos os vizinhos diretos

Melhor usado quando:
- Precisamos encontrar o caminho mais curto em arestas não ponderadas
- Queremos explorar o grafo em níveis
- Necessitamos visitar todos os vértices alcançáveis
- Precisamos determinar componentes conexos

Complexidade:
- Tempo: O(V²) onde V é o número de vértices
- Espaço: O(V) para a fila e vetor de visitados
*/

void bfs(vector<vector<int>>& grafo, int inicio) {
    int n = grafo.size();
    vector<bool> visitado(n, false);
    vector<int> nivel(n, -1);
    queue<int> fila;
    
    visitado[inicio] = true;
    nivel[inicio] = 0;
    fila.push(inicio);
    
    cout << "Ordem de visitação: ";
    
    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();
        cout << atual << " ";
        
        for (int i = 0; i < n; i++) {
            if (grafo[atual][i] && !visitado[i]) {
                visitado[i] = true;
                nivel[i] = nivel[atual] + 1;
                fila.push(i);
            }
        }
    }
    cout << "\n\n";
    
    cout << "Níveis dos vértices:\n";
    for (int i = 0; i < n; i++) {
        if (nivel[i] != -1) {
            cout << "Vértice " << i << ": nível " << nivel[i] << "\n";
        } else {
            cout << "Vértice " << i << ": não alcançável\n";
        }
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
    cout << "Iniciando BFS a partir do vértice " << verticeInicial << "\n\n";
    
    bfs(grafo, verticeInicial);
    
    return 0;
}