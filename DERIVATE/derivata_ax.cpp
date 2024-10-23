#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_ax(double a, double x) {
    return pow(a, x) * log(a);
}

int main() {
    double a, x;
    std::cout << "Introduceti valoarea lui a: ";
    std::cin >> a;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_ax(a, x);
    std::cout << "Derivata lui " << a << "^" << x << " este " << rezultat << std::endl;
    
    system("pause");
    return 0;
}
