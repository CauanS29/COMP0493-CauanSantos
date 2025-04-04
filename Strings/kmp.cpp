/**
 * Algoritmo Knuth-Morris-Pratt (KMP)
 * Complexidade: O(n + m), onde n é o tamanho do texto e m é o tamanho do padrão
 */

#include <vector>
#include <string>

std::vector<int> computeLPS(const std::string& pattern) {
    int m = pattern.size();
    std::vector<int> lps(m, 0);
    
    int len = 0;
    int i = 1;
    
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    
    return lps;
}

std::vector<int> KMP(const std::string& text, const std::string& pattern) {
    std::vector<int> matches;
    int n = text.size();
    int m = pattern.size();
    
    if (m == 0) return matches;
    
    std::vector<int> lps = computeLPS(pattern);
    
    int i = 0; // índice para o texto
    int j = 0; // índice para o padrão
    
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    
    return matches;
}
