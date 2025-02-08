#include <bits/stdc++.h>
using namespace std;

/*
Área da Seção Transversal - Geometria Computacional

Funcionamento:
- Calcula a área da seção transversal de uma figura geométrica
- Usa o método dos trapézios para aproximar a área
- Permite calcular áreas de diferentes formas geométricas
- Implementa cálculo para círculo e elipse como exemplos

Fórmulas utilizadas:
- Círculo: A = π * r²
*/

const double PI = 3.14159265358979323846;

struct Circulo {
    double raio;
    
    Circulo(double r) : raio(r) {}
    
    double area() const {
        return PI * raio * raio;
    }
};


void imprimirResultado(const string& forma, double area) {
    cout << "Área da seção transversal do(a) " << forma << ": "
         << fixed << setprecision(4) << area << "\n";
}

int main() {

    Circulo circulo(5.0);
    imprimirResultado("círculo", circulo.area());
    

    
    
    cout << "\nTestando diferentes raios do círculo:\n";
    vector<double> raios = {1.0, 2.0, 3.0, 4.0};
    for (double r : raios) {
        Circulo c(r);
        cout << "Raio = " << r << ": Área = " 
             << fixed << setprecision(4) << c.area() << "\n";
    }
    
    
    return 0;
}
