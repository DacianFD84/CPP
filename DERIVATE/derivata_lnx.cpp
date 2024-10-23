#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_ln(double x) {
    return 1.0 / x;
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_ln(x);
    std::cout << "Derivata lui ln(" << x << ") este " << rezultat << std::endl;
    
    system("pause");
    
    return 0;
}
