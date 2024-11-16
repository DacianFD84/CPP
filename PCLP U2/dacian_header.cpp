#include <iostream>
#include "dacian.h"
#include "snippets.h"
using namespace std;

int main() {
    double num1, num2;

    // Solicitare de la utilizator pentru primul număr
    get_input("Introdu primul numar: ", num1);

    // Solicitare de la utilizator pentru al doilea număr
    get_input("Introdu al doilea numar: ", num2);

    // Calcularea sumei celor două numere
    double suma = suma_a_doua_numere(num1, num2);

    // Afișarea rezultatului folosind funcția print
    print("Suma celor doua numere este: ", suma);

    // Pregătirea mesajului pentru scrierea în fișier
    string mesaj = "Suma celor doua numere este: " + std::to_string(suma);

    // Numele fișierului în care se scrie
    string filename = "output.txt";

    // Scrierea rezultatului în fișier folosind write_to_file
    write_to_file(filename, mesaj);

    // Pregătește mesajul complet pentru fișier
    string mesaj_fisier = "Rezultatul a fost scris in fisierul: " + filename;
    write_to_file(filename, mesaj_fisier); // Scrie mesajul complet în fișier.

    // Utilizarea funcției print pentru a informa utilizatorul despre scrierea în fișier
    print("Rezultatul a fost scris in fisierul: ", filename);

    return 0;
}
