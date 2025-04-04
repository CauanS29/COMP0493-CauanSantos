#include <iostream>
#include <vector>
using namespace std;

class UnionFind {
private:
    vector<int> parent;  // Array para armazenar o pai de cada elemento
    vector<int> rank;    // Array para armazenar a altura/rank da árvore

public:
    // Construtor: inicializa o conjunto com n elementos
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Inicialmente, cada elemento é pai de si mesmo
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Encontra o representante (raiz) de um conjunto com compressão de caminho
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Compressão de caminho
        }
        return parent[x];
    }

    // Une dois conjuntos por rank (união por classificação)
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        
        // Já estão no mesmo conjunto
        if (rootX == rootY) return;
        
        // União por rank: anexa a árvore de menor rank à árvore de maior rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            // Se ambos têm o mesmo rank, então escolhe um como raiz e incrementa seu rank
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    // Verifica se dois elementos estão no mesmo conjunto
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    // Retorna o número de conjuntos disjuntos
    int count() {
        int count = 0;
        for (int i = 0; i < parent.size(); i++) {
            if (parent[i] == i) {
                count++;
            }
        }
        return count;
    }
};

