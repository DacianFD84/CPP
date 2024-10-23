#include <iostream>
#include <cmath>

// Funcția pentru calculul derivării
double calculeaza_derivata(double x, int n) {
    return n * pow(x, n - 1);
}

int main() {
    double x;
    int n;
    
    // Cerere input pentru valoarea lui x
    std::cout << "Introdu valoarea lui x: ";
    std::cin >> x;
    
    // Cerere input pentru valoarea lui n
    std::cout << "Introdu valoarea lui n: ";
    std::cin >> n;

    // Calcularea derivării
    double rezultat = calculeaza_derivata(x, n);
    
    // Afișarea rezultatului
    std::cout << "Derivata funcției x^" << n << " este: " << rezultat << std::endl;
    
    system("pause");
    
    return 0;
}
