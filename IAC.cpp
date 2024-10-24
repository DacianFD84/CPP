#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Introducerea temperaturii initiale
    double T0;
    cout << "Introduceti temperatura initiala (T0): ";
    cin >> T0;

    // Introducerea ratei de schimbare a temperaturii (u)
    double u;
    cout << "Introduceti rata de schimbare a temperaturii (u): ";
    cin >> u;

    // Valoarea timpului (t) pentru care dorim sa calculam T(t)
    double t;
    cout << "Introduceti timpul (t): ";
    cin >> t;

    // Calculul temperaturii T(t) la timpul t conform formulei
    double C; // Constanta de integrare
    cout << "Introduceti constanta de integrare (C): ";
    cin >> C;

    // Calculul final pentru T(t)
    double T = (1.0 / 4.0) * (u * t) + C;

    // Afisarea rezultatului
    cout << fixed << setprecision(2); // Setam precizia la 2 zecimale
    cout << "Valoarea temperaturii la t = " << t << " este: " << T0 + T << " grade" << endl;
    system("pause");
    return 0;
}
