#include <iostream>
using namespace std;

int main() {
    int num1, num2, suma;

    // Solicită introducerea primului număr
    cout << "Introdu primul numar: ";
    cin >> num1;

    // Solicită introducerea celui de-al doilea număr
    cout << "Introdu al doilea numar: ";
    cin >> num2;

    // Calculează suma celor două numere
    suma = num1 + num2;

    // Afișează rezultatul
    cout << "Suma celor doua numere este: " << suma << endl;

    // Așteaptă să se apese o tastă înainte de a închide fereastra
    system("pause");

    return 0;
}
