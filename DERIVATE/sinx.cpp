#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_sin(double x) {
    return cos(x);
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_sin(x);
    std::cout << "Derivata lui sin(" << x << ") este " << rezultat << std::endl;
    
    system("pause");
    
    return 0;
}
