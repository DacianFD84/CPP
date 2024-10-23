#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_radical_n(double x, int n) {
    return (1.0 / n) * pow(x, (1.0 / n) - 1);
}

int main() {
    double x;
    int n;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;
    std::cout << "Introduceti valoarea lui n: ";
    std::cin >> n;

    double rezultat = derivata_radical_n(x, n);
    std::cout << "Derivata lui radical " << n << " din " << x << " este " << rezultat << std::endl;
  
    system("pause");
     return 0;
}
