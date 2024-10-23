#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_cos(double x) {
    return -sin(x);
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_cos(x);
    std::cout << "Derivata lui cos(" << x << ") este " << rezultat << std::endl;
    system("pause");
    return 0;
}
