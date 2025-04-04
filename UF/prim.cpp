#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

struct Aresta {
    int destino;
    int peso;
};

struct Comparador {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; 
    }
};

class Grafo {
private:
    int V; 
    vector<vector<Aresta>> adj; 

public:
   
    Grafo(int vertices) : V(vertices) {
        adj.resize(V);
    }
    
    void adicionarAresta(int origem, int destino, int peso) {
        adj[origem].push_back({destino, peso});
        adj[destino].push_back({origem, peso});
    }
    
    vector<pair<int, int>> prim() {
        // Vetor para armazenar as arestas da AGM (pai, vértice)
        vector<pair<int, int>> arvoreGeradoraMinima;
        
        // Vetor para marcar vértices já incluídos na AGM
        vector<bool> incluido(V, false);
        
        // Vetor para armazenar o peso mínimo de borda para cada vértice
        vector<int> chave(V, numeric_limits<int>::max());
        
        // Vetor para armazenar o pai de cada vértice na AGM
        vector<int> pai(V, -1);
        
        // Fila de prioridade para selecionar o vértice com menor chave
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparador> pq;
        
        // Começar com o vértice 0
        int origem = 0;
        chave[origem] = 0;
        pq.push({origem, 0});
        
        while (!pq.empty()) {
           
            int u = pq.top().first;
            pq.pop();
            
           
            if (incluido[u])
                continue;
            
           
            incluido[u] = true;
            
          
            if (u != origem) {
                arvoreGeradoraMinima.push_back({pai[u], u});
            }
            
           
            for (const Aresta& aresta : adj[u]) {
                int v = aresta.destino;
                int peso = aresta.peso;
                
               
                if (!incluido[v] && peso < chave[v]) {
                   
                    pai[v] = u;
                    chave[v] = peso;
                    pq.push({v, chave[v]});
                }
            }
        }
        
        return arvoreGeradoraMinima;
    }
    
    int calcularPesoTotal(const vector<pair<int, int>>& agm) {
        int pesoTotal = 0;
        
        for (const auto& aresta : agm) {
            int u = aresta.first;
            int v = aresta.second;
            
            for (const Aresta& e : adj[u]) {
                if (e.destino == v) {
                    pesoTotal += e.peso;
                    break;
                }
            }
        }
        
        return pesoTotal;
    }
};
