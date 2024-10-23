#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_cot(double x) {
    return -1 / (sin(x) * sin(x)); // echivalentul lui -csc^2(x)
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_cot(x);
    std::cout << "Derivata lui cot(" << x << ") este " << rezultat << std::endl;

    system("pause");
    return 0;
}
