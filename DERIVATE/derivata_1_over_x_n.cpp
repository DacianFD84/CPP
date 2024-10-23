#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_1_over_x_n(double x, int n) {
    return -n * pow(x, -(n+1));
}

int main() {
    double x;
    int n;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;
    std::cout << "Introduceti valoarea lui n: ";
    std::cin >> n;

    double rezultat = derivata_1_over_x_n(x, n);
    std::cout << "Derivata lui 1/(x^" << n << ") este " << rezultat << std::endl;

    return 0;
}
