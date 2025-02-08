#include <bits/stdc++.h>
using namespace std;

/*
Distância Ponto-Reta - Geometria Computacional

Funcionamento:
- Usa a fórmula: d = |ax0 + by0 + c| / sqrt(a² + b²)
- Onde (x0,y0) é o ponto e ax + by + c = 0 é a equação da reta
- Também implementa cálculo usando dois pontos da reta

Fórmulas utilizadas:
- Forma geral da reta: ax + by + c = 0
- Distância entre ponto e reta: |ax0 + by0 + c| / sqrt(a² + b²)
- Distância usando dois pontos da reta: 
  |det([p2-p1, p-p1])| / |p2-p1|
*/

struct Ponto {
    double x, y;
    
    Ponto(double x = 0, double y = 0) : x(x), y(y) {}
    
    Ponto operator-(const Ponto& p) const {
        return Ponto(x - p.x, y - p.y);
    }
};


double distanciaPontoReta(double a, double b, double c, Ponto p) {
    return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
}

double distanciaPontoReta(Ponto p1, Ponto p2, Ponto p) {
    if (p1.x == p2.x && p1.y == p2.y) {
        return sqrt(pow(p.x - p1.x, 2) + pow(p.y - p1.y, 2));
    }
    
    double numerador = abs((p2.x - p1.x) * (p1.y - p.y) - (p1.x - p.x) * (p2.y - p1.y));
    double denominador = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    
    return numerador / denominador;
}

int main() {
    cout << "Teste usando equação da reta (2x + 3y - 6 = 0):\n";
    double a = 2, b = 3, c = -6;
    Ponto p1(1, 2);
    cout << "Distância do ponto (1,2) à reta: " 
         << fixed << setprecision(4) 
         << distanciaPontoReta(a, b, c, p1) << "\n\n";
    
    cout << "Teste usando dois pontos da reta:\n";
    Ponto r1(0, 2), r2(2, 0);  
    Ponto p2(1, 2);            
    cout << "Distância do ponto (1,2) à reta que passa por (0,2) e (2,0): " 
         << fixed << setprecision(4) 
         << distanciaPontoReta(r1, r2, p2) << "\n";
    
    return 0;
}
