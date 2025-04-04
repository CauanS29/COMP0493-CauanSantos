/**
 * Cálculo do Coeficiente Binomial C(n,k) de forma analítica
 * Implementação baseada na fórmula: C(n,k) = n! / (k! * (n-k)!)
 */

#include <iostream>
using namespace std;

unsigned long long fatorial(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

unsigned long long coeficienteBinomialAnalitico(int n, int k) {
    if (k > n - k) {
        k = n - k;
    }
    
  
    unsigned long long resultado = 1;
    
    
    for (int i = 0; i < k; i++) {
        resultado *= (n - i);
        resultado /= (i + 1);
    }
    
    return resultado;
}
