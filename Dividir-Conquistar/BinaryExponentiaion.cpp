#include <bits/stdc++.h>
using namespace std;

/*
Binary Exponentiation - Algoritmo de Divisão e Conquista

Funcionamento:
- Calcula x^n usando a propriedade: x^n = (x^(n/2))^2 se n é par
                                   x^n = x * (x^(n/2))^2 se n é ímpar
- Divide o expoente pela metade a cada passo
- Combina os resultados multiplicando adequadamente

Melhor usado quando:
- É necessário calcular potências com expoentes grandes
- Precisão e eficiência são importantes
- O módulo pode ser necessário (para evitar overflow)

Complexidade:
- Tempo: O(log n) onde n é o expoente
- Espaço: O(log n) devido à pilha de recursão
*/


long long binPowRecursive(long long x, long long n) {
    if (n == 0) return 1;
    
    long long half = binPowRecursive(x, n / 2);
    
    if (n % 2 == 0) {
        return half * half;
    } else {
        return x * half * half;
    }
}


long long binPowMod(long long x, long long n, long long m) {
    if (n == 0) return 1;
    
    long long half = binPowMod(x, n / 2, m);
    half = (half * half) % m;
    
    if (n % 2 == 0) {
        return half;
    } else {
        return (x * half) % m;
    }
}

int main() {
    
    cout << "2^10 = " << binPowRecursive(2, 10) << "\n";
    cout << "3^5 = " << binPowRecursive(3, 5) << "\n";
    cout << "5^3 = " << binPowRecursive(5, 3) << "\n\n";
    

    cout << "Testes com módulo (mod 1000000007):\n";
    long long mod = 1000000007;
    cout << "2^10 mod " << mod << " = " << binPowMod(2, 10, mod) << "\n";
    cout << "3^15 mod " << mod << " = " << binPowMod(3, 15, mod) << "\n\n";
    
    
    return 0;
}
