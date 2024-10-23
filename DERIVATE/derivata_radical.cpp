#include <iostream>
#include <cmath>

// Funcția pentru calculul derivării
double calculeaza_derivata_radical(double x) {
    return 0.5 * pow(x, -0.5);
}

int main() {
    double x;

    // Cerere input pentru valoarea lui x
    std::cout << "Introdu valoarea lui x: ";
    std::cin >> x;

    // Calcularea derivării
    double rezultat = calculeaza_derivata_radical(x);

    // Afișarea rezultatului
    std::cout << "Derivata funcției sqrt(x) pentru x = " << x << " este: " << rezultat << std::endl;
    
    system("pause");

    return 0;
}
