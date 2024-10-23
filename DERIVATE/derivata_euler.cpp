#include <iostream>
#include <cmath>

// Funcția pentru derivată
double derivata_ex(double x) {
    return exp(x); // exp(x) reprezintă e^x în C++
}

int main() {
    double x;
    std::cout << "Introduceti valoarea lui x: ";
    std::cin >> x;

    double rezultat = derivata_ex(x);
    std::cout << "Derivata lui e^" << x << " este " << rezultat << std::endl;
   
    system("pause");
    
    return 0;
}
