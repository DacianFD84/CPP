#include <iostream>
#include <cmath>

// Definim funcția f(x, y) din ecuația diferențială dy/dx = f(x, y)
double f(double x, double y) {
    return x + y; // Exemplu: dy/dx = x + y
}

// Implementăm metoda Euler pentru a rezolva ecuația diferențială
void metodaEuler(double x0, double y0, double x_final, double pas) {
    double x = x0;
    double y = y0;

    // Iterăm până când ajungem la valoarea dorită a lui x
    while (x < x_final) {
        y = y + pas * f(x, y); // Actualizăm valoarea lui y
        x = x + pas;           // Avansăm în x
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
}

int main() {
    // Definim variabile pentru inputul utilizatorului
    double x0, y0, x_final, pas;

    // Cerem utilizatorului să introducă condițiile inițiale și parametrii
    std::cout << "Introduceți valoarea inițială pentru x (x0): ";
    std::cin >> x0;

    std::cout << "Introduceți valoarea inițială pentru y (y0): ";
    std::cin >> y0;

    std::cout << "Introduceți valoarea finală pentru x (x_final): ";
    std::cin >> x_final;

    std::cout << "Introduceți pasul de integrare: ";
    std::cin >> pas;

    // Apelăm funcția de rezolvare
    metodaEuler(x0, y0, x_final, pas);

    system("pause");
    
    return 0;
}
