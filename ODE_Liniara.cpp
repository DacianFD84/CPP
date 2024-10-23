#include <iostream>
using namespace std;

// Functia derivata: dy/dx = x
double f(double x) {
    return x;
}

int main() {
    // Valori initiale
    double x0, y0, x_final, pas;
    
    // Introducerea valorilor initiale
    cout << "Introduceti valoarea initiala pentru x (x0): ";
    cin >> x0;
    cout << "Introduceti valoarea initiala pentru y (y0): ";
    cin >> y0;
    cout << "Introduceti valoarea finala pentru x (x_final): ";
    cin >> x_final;
    cout << "Introduceti pasul de integrare: ";
    cin >> pas;
    
    // Metoda Euler pentru rezolvarea numerica
    double x = x0;
    double y = y0;

    while (x <= x_final) {
        // Afiseaza valoarea curenta a lui x si y
        cout << "x: " << x << ", y: " << y << endl;
        
        // Aplicam metoda Euler: y_next = y + h * f(x)
        y = y + pas * f(x);
        
        // Actualizam valoarea lui x
        x = x + pas;
    }
    system("pause");
    return 0;
}
