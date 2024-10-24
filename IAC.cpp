#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Introducerea temperaturii initiale
    double T0;
    cout << "Introduceti temperatura initiala (T0): ";
    cin >> T0;

    // Introducerea ratei de schimbare a temperaturii (u(t))
    double u;
    cout << "Introduceti rata de schimbare a temperaturii (u): ";
    cin >> u;

    // Valoarea timpului (t) pentru care dorim sa calculam T(t)
    double t;
    cout << "Introduceti timpul (t): ";
    cin >> t;

    // Calculul temperaturii T(t) la timpul t
    double T = T0 + u * t; // Temperatura este temperatura initiala plus rata de schimbare inmultita cu timpul

    // Afisarea rezultatului
    cout << fixed << setprecision(2); // Setam precizia la 2 zecimale
    cout << "Valoarea temperaturii la t = " << t << " este: " << T << " grade" << endl;

    return 0;
}
