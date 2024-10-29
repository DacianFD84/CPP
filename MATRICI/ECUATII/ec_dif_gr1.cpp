#include <iostream>
#include <iomanip>

int main() {
    // Cerem utilizatorului să introducă valoarea lui k
    double k;
    std::cout << "Introduceti valoarea lui k: ";
    std::cin >> k;

    // Cerem utilizatorului să introducă valoarea inițială y(0)
    double C;
    std::cout << "Introduceti valoarea initiala y(0): ";
    std::cin >> C;

    // Cerem utilizatorului să introducă valoarea lui x
    double x_val;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x_val;

    // Calculăm y folosind formula y = k * x + C
    double y = k * x_val + C;

    // Afișăm soluția pentru y la x specificat
    std::cout << std::fixed << std::setprecision(2); // Setăm precizia la 2 zecimale
    std::cout << "Valoarea lui y pentru x = " << x_val << " este: y = " << y << std::endl;
    system("pause");
    return 0;
}
