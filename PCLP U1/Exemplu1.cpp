#include <iostream>

int main() {
    // Declarăm variabilele
    double a, b, x, E;

    // Citim datele de intrare
    std::cout << "Introdu valoarea pentru a: ";
    std::cin >> a;
    
    std::cout << "Introdu valoarea pentru b: ";
    std::cin >> b;
    
    std::cout << "Introdu valoarea pentru x: ";
    std::cin >> x;

    // Calculăm expresia E = a * x + b - 2.68
    E = a * x + b - 2.68;

    // Afișăm rezultatul
    std::cout << "Valoarea lui E este: " << E << std::endl;
    system("pause");
    return 0;
}
