#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_tan(double x) {
    return 1 / (cos(x) * cos(x)); // echivalentul lui sec^2(x)
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_tan(x);
    std::cout << "Derivata lui tan(" << x << ") este " << rezultat << std::endl;
    system("pause");
    return 0;
}
