#include <iostream>
using namespace std;

int main() {
    float a, b, x;

    // Citim coeficientii a si b
    cout << "Introduceti coeficientul a: ";
    cin >> a;
    cout << "Introduceti termenul liber b: ";
    cin >> b;

    // Verificam daca a este 0
    if (a == 0) {
        if (b == 0) {
            cout << "Infinit de solutii (toate valorile lui x sunt solutii)." << endl;
        } else {
            cout << "Nu exista solutii (ecuatia este contradictorie)." << endl;
        }
    } else {
        // Calculam x
        x = -b / a;
        cout << "Solutia ecuatiei este: x = " << x << endl;
    }
    
    // Opțional, pauză pentru a vedea rezultatul înainte de a închide fereastra
    system("pause"); 
    return 0;
}
