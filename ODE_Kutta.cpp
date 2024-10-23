#include <iostream>
#include <cmath>

// Definim funcția f(x, y) care reprezintă derivata dy/dx
double f(double x, double y) {
    return x + y; // Exemplu: dy/dx = x + y
}

// Implementăm metoda Runge-Kutta de ordin 4 (RK4)
void metodaRungeKutta(double x0, double y0, double x_final, double pas) {
    double x = x0;
    double y = y0;

    // Iterăm până la valoarea finală a lui x
    while (x < x_final) {
        // Calculăm coeficienții metodei Runge-Kutta
        double k1 = pas * f(x, y);
        double k2 = pas * f(x + pas / 2.0, y + k1 / 2.0);
        double k3 = pas * f(x + pas / 2.0, y + k2 / 2.0);
        double k4 = pas * f(x + pas, y + k3);

        // Actualizăm valoarea lui y
        y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6.0;

        // Avansăm în x
        x = x + pas;

        // Afișăm rezultatul intermediar
        std::cout << "x: " << x << ", y: " << y << std::endl;
    }
}

int main() {
    // Definim variabile pentru inputul utilizatorului
    double x0, y0, x_final, pas;

    // Cerem utilizatorului să introducă condițiile inițiale și parametrii
    std::cout << "Introduceti valoarea initiala pentru x (x0): ";
    std::cin >> x0;

    std::cout << "Introduceti valoarea initiala pentru y (y0): ";
    std::cin >> y0;

    std::cout << "Introduceti valoarea finala pentru x (x_final): ";
    std::cin >> x_final;

    std::cout << "Introduceti pasul de integrare: ";
    std::cin >> pas;

    // Apelăm funcția de rezolvare prin metoda Runge-Kutta de ordin 4
    metodaRungeKutta(x0, y0, x_final, pas);
    system("pause");
    return 0;
}
