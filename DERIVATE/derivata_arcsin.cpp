#include <iostream>
#include <cmath>
#include <limits>

// Funcția pentru derivată
double derivata_arcsin(double x) {
    if (x > -1 && x < 1) {
        return 1 / sqrt(1 - x * x);
    } else if (x == 1 || x == -1) {
        std::cerr << "Derivata este nedefinita la x = " << x << "." << std::endl;
        return std::numeric_limits<double>::max();
    } else {
        std::cerr << "Eroare: x trebuie sa fie in intervalul [-1, 1]." << std::endl;
        return std::numeric_limits<double>::quiet_NaN();
    }
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_arcsin(x);
    if (!std::isnan(rezultat)) {
        std::cout << "Derivata lui arcsin(" << x << ") este " << rezultat << std::endl;
    }

    return 0;
}