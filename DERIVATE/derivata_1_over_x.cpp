#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_1_over_x(double x) {
    return -1.0 / (x * x);
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_1_over_x(x);
    std::cout << "Derivata lui 1/" << x << " este " << rezultat << std::endl;
    
    system("pause");
    return 0;
}
