#include <bits/stdc++.h>
using namespace std;

/*
Lista de Adjacência - Estrutura de Dados para Grafos

Funcionamento:
- Representa um grafo usando um vetor de listas
- Cada vértice possui uma lista de seus vizinhos
- Armazena apenas as arestas existentes
- Permite fácil iteração sobre os vizinhos de um vértice

Melhor usado quando:
- O grafo é esparso (poucas arestas)
- Precisamos frequentemente listar os vizinhos de um vértice
- Memória é uma preocupação
- Necessitamos adicionar/remover arestas dinamicamente

Complexidade:
- Espaço: O(V + E) onde V é o número de vértices e E o número de arestas
- Tempo para verificar adjacência: O(grau(v))
- Tempo para listar vizinhos: O(grau(v))
*/

class Grafo {
private:
    int V; 
    vector<vector<int>> adj; 
    bool direcionado; 

public:
    Grafo(int V, bool direcionado = false) {
        this->V = V;
        this->direcionado = direcionado;
        adj.resize(V);
    }

    void adicionarAresta(int v1, int v2) {
        adj[v1].push_back(v2);
        if (!direcionado) {
            adj[v2].push_back(v1);
        }
    }

    void removerAresta(int v1, int v2) {
        adj[v1].erase(remove(adj[v1].begin(), adj[v1].end(), v2), adj[v1].end());
        if (!direcionado) {
            adj[v2].erase(remove(adj[v2].begin(), adj[v2].end(), v1), adj[v2].end());
        }
    }

    bool existeAresta(int v1, int v2) {
        return find(adj[v1].begin(), adj[v1].end(), v2) != adj[v1].end();
    }

    vector<int> vizinhos(int v) {
        return adj[v];
    }

    void imprimirGrafo() {
        for (int v = 0; v < V; v++) {
            cout << "Vértice " << v << " -> ";
            for (int vizinho : adj[v]) {
                cout << vizinho << " ";
            }
            cout << "\n";
        }
    }

    int numeroVertices() {
        return V;
    }

    int numeroArestas() {
        int arestas = 0;
        for (int v = 0; v < V; v++) {
            arestas += adj[v].size();
        }
        return direcionado ? arestas : arestas/2;
    }
};

int main() {
    
    Grafo g(6); 

    
    g.adicionarAresta(0, 1);
    g.adicionarAresta(0, 2);
    g.adicionarAresta(1, 3);
    g.adicionarAresta(2, 3);
    g.adicionarAresta(3, 4);
    g.adicionarAresta(4, 5);

    cout << "Representação do grafo em lista de adjacência:\n";
    g.imprimirGrafo();
    cout << "\n";

    cout << "Número de vértices: " << g.numeroVertices() << "\n";
    cout << "Número de arestas: " << g.numeroArestas() << "\n\n";

   

    return 0;
}