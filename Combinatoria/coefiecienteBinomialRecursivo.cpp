/**
 * Cálculo do Coeficiente Binomial C(n,k) de forma recursiva
 * Implementação baseada na propriedade C(n,k) = C(n-1,k-1) + C(n-1,k)
 */

#include <iostream>
using namespace std;

long long binomialCoeficienteRecursivo(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    
    return binomialCoeficienteRecursivo(n - 1, k - 1) + binomialCoeficienteRecursivo(n - 1, k);
}

