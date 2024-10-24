#include <iostream>
using namespace std;

int main() {
    double T0, u, t, C;

    // Introducerea valorilor
    cout << "Introduceti temperatura initiala (T0): ";
    cin >> T0;
    cout << "Introduceti rata de schimbare a temperaturii (u): ";
    cin >> u;
    cout << "Introduceti timpul (t): ";
    cin >> t;
    cout << "Introduceti constanta de integrare (C): ";
    cin >> C;

    // Calculul temperaturii
    double integral = u * t;  // Integrarea simplificată
    double y_t = (1.0 / 4.0) * integral + C; // Aplicam formula y(t)

    // Afișarea rezultatului
    cout << "Valoarea temperaturii la t = " << t << " este: " << y_t << " grade" << endl;
    
    system("pause");
    return 0;
}
