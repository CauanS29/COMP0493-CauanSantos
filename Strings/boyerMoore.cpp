/**
 * Algoritmo Boyer-Moore para busca de padrões em strings
 * Complexidade: O(n + m) no melhor caso, O(n*m) no pior caso
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::unordered_map<char, int> badCharRule(const std::string& pattern) {
    std::unordered_map<char, int> badChar;
    int m = pattern.size();
    
    for (int i = 0; i < m - 1; i++) {
        badChar[pattern[i]] = i;
    }
    
    return badChar;
}
void precomputeSuffixes(const std::string& pattern, std::vector<int>& suffixes) {
    int m = pattern.size();
    int g = m - 1;
    int f = 0;
    
    suffixes[m - 1] = m;
    
    for (int i = m - 2; i >= 0; --i) {
        if (i > g && suffixes[i + m - 1 - f] < i - g) {
            suffixes[i] = suffixes[i + m - 1 - f];
        } else {
            if (i < g) {
                g = i;
            }
            f = i;
            
            while (g >= 0 && pattern[g] == pattern[g + m - 1 - f]) {
                --g;
            }
            
            suffixes[i] = f - g;
        }
    }
}

std::vector<int> goodSuffixRule(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> suffixes(m, 0);
    std::vector<int> goodSuffix(m, 0);
    
    precomputeSuffixes(pattern, suffixes);
    
    for (int i = 0; i < m; ++i) {
        goodSuffix[i] = m;
    }
    
    int j = 0;
    for (int i = m - 1; i >= 0; --i) {
        if (suffixes[i] == i + 1) {
            for (; j < m - 1 - i; ++j) {
                if (goodSuffix[j] == m) {
                    goodSuffix[j] = m - 1 - i;
                }
            }
        }
    }
    
    for (int i = 0; i <= m - 2; ++i) {
        goodSuffix[m - 1 - suffixes[i]] = m - 1 - i;
    }
    
    return goodSuffix;
}

std::vector<int> BoyerMoore(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    
    if (m == 0 || m > n) return matches;
    
    auto badChar = badCharRule(pattern);
    auto goodSuffix = goodSuffixRule(pattern);
    
    int s = 0;  // s é o deslocamento do padrão em relação ao texto
    
    while (s <= n - m) {
        int j = m - 1;
        
        // Compara da direita para a esquerda
        while (j >= 0 && pattern[j] == text[s + j]) {
            --j;
        }
        
        // Padrão encontrado
        if (j < 0) {
            matches.push_back(s);
            
            // Desloca o padrão para a próxima ocorrência
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        } else {
            // Calcula o deslocamento usando as duas regras
            int badCharShift = j - (badChar.find(text[s + j]) != badChar.end() ? badChar[text[s + j]] : -1);
            int goodSuffixShift = goodSuffix[j];
            
            // Usa o maior deslocamento
            s += std::max(badCharShift, goodSuffixShift);
        }
    }
    
    return matches;
}
