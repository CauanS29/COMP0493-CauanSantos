#include <iostream>
#include <vector>
#include <algorithm>
#include "unionFind.cpp"
using namespace std;

// Estrutura para representar uma aresta em um grafo ponderado
struct Aresta {
    int origem;
    int destino;
    int peso;
    
    // Operador para comparação de arestas (usado na ordenação)
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

// Estrutura para representar um grafo ponderado
class Grafo {
private:
    int V; // Número de vértices
    vector<Aresta> arestas; // Lista de arestas

public:
    // Construtor
    Grafo(int vertices) : V(vertices) {}
    
    // Adiciona uma aresta ao grafo
    void adicionarAresta(int origem, int destino, int peso) {
        Aresta aresta = {origem, destino, peso};
        arestas.push_back(aresta);
    }
    
    // Algoritmo de Kruskal para encontrar a Árvore Geradora Mínima
    vector<Aresta> kruskal() {
        vector<Aresta> arvoreGeradoraMinima;
        
        // Ordenar as arestas por peso em ordem crescente
        sort(arestas.begin(), arestas.end());
        
        // Criar uma estrutura Union-Find
        UnionFind uf(V);
        
        // Processar todas as arestas ordenadas
        for (const Aresta& aresta : arestas) {
            int origem = aresta.origem;
            int destino = aresta.destino;
            
            // Verificar se adicionar esta aresta forma um ciclo
            if (!uf.connected(origem, destino)) {
                // Incluir na Árvore Geradora Mínima
                arvoreGeradoraMinima.push_back(aresta);
                
                // Unir os conjuntos
                uf.unite(origem, destino);
                
                // Se já adicionamos V-1 arestas, a AGM está completa
                if (arvoreGeradoraMinima.size() == V - 1) {
                    break;
                }
            }
        }
        
        return arvoreGeradoraMinima;
    }
};

