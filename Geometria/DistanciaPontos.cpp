#include <bits/stdc++.h>
using namespace std;

/*
Distância entre Pontos - Geometria Computacional

Funcionamento:
- Calcula a distância euclidiana entre dois pontos no plano
- Usa a fórmula da distância: d = √[(x2-x1)² + (y2-y1)²]
- Permite cálculo de distância entre múltiplos pontos

Fórmulas utilizadas:
- Distância Euclidiana: √[(x2-x1)² + (y2-y1)²]
*/

struct Ponto {
    double x, y;
    
    Ponto(double x = 0, double y = 0) : x(x), y(y) {}
};

double distanciaEuclidiana(const Ponto& p1, const Ponto& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}


void imprimirDistancias(const Ponto& p1, const Ponto& p2) {
    cout << "Entre os pontos (" << p1.x << "," << p1.y << ") e ("
         << p2.x << "," << p2.y << "):\n";
    cout << "Distância Euclidiana: " << fixed << setprecision(4) 
         << distanciaEuclidiana(p1, p2) << "\n";
}

int main() {
    vector<pair<Ponto, Ponto>> pontos = {
        {Ponto(0, 0), Ponto(3, 4)},
        {Ponto(1, 1), Ponto(4, 5)},
        {Ponto(-2, 3), Ponto(2, -1)}
    };
    
    cout << "Calculando distâncias entre pontos:\n\n";
    
    for (const auto& par : pontos) {
        imprimirDistancias(par.first, par.second);
    }
    
    return 0;
}
