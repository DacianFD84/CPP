#include <iostream>
using namespace std;

int main() {
    // Definirea variabilelor A si B
    int A, B;

    // Solicită utilizatorului sa introduca valorile pentru A si B
    cout << "Introdu valoarea pentru A (0 sau 1): ";
    cin >> A;
    cout << "Introdu valoarea pentru B (0 sau 1): ";
    cin >> B;

    // Verifica daca A si B sunt valori valide (0 sau 1)
    if ((A != 0 && A != 1) || (B != 0 && B != 1)) {
        cout << "Valori invalide! A si B trebuie sa fie 0 sau 1." << endl;
        return 1;
    }

    // Operarea logica AND
    int andResult = A & B;  // AND: A & B -> 1 & 0 => 0 (rezultatul va fi 0)
    cout << "AND: " << andResult << endl;
    cout << "Explicatie: Rezultatul este 1 doar daca ambele intrari sunt 1. "
         << "A & B -> " << A << " & " << B << " => " << andResult << endl;

    // Operarea logica OR
    int orResult = A | B;   // OR: A | B -> 1 | 0 => 1 (rezultatul va fi 1)
    cout << "OR: " << orResult << endl;
    cout << "Explicatie: Rezultatul este 1 daca cel putin una dintre intrari este 1. "
         << "A | B -> " << A << " | " << B << " => " << orResult << endl;

    // Operarea logica XOR
    int xorResult = A ^ B;  // XOR: A ^ B -> 1 ^ 0 => 1 (rezultatul va fi 1)
    cout << "XOR: " << xorResult << endl;
    cout << "Explicatie: Rezultatul este 1 daca intrarile sunt diferite. "
         << "A ^ B -> " << A << " ^ " << B << " => " << xorResult << endl;

    // Operarea logica NOT (inverseaza valoarea lui A)
    int notA = !A;          // NOT: A -> !1 => 0 (rezultatul va fi 0)
    cout << "NOT A: " << notA << endl;
    cout << "Explicatie: Rezultatul este inversul valorii lui A. "
         << "NOT A -> !" << A << " => " << notA << endl;

    // Operarea logica NAND (inversul lui AND)
    int nandResult = !(A & B); // NAND: !(A & B) -> !(1 & 0) => !0 => 1 (rezultatul va fi 1)
    cout << "NAND: " << nandResult << endl;
    cout << "Explicatie: Rezultatul este inversul lui AND. "
         << "NAND -> !(A & B) -> !(" << A << " & " << B << ") => " << nandResult << endl;

    // Operarea logica NOR (inversul lui OR)
    int norResult = !(A | B);  // NOR: !(A | B) -> !(1 | 0) => !1 => 0 (rezultatul va fi 0)
    cout << "NOR: " << norResult << endl;
    cout << "Explicatie: Rezultatul este inversul lui OR. "
         << "NOR -> !(A | B) -> !(" << A << " | " << B << ") => " << norResult << endl;

    // Operarea logica XNOR (inversul lui XOR)
    int xnorResult = !(A ^ B); // XNOR: !(A ^ B) -> !(1 ^ 0) => !1 => 0 (rezultatul va fi 0)
    cout << "XNOR: " << xnorResult << endl;
    cout << "Explicatie: Rezultatul este inversul lui XOR. "
         << "XNOR -> !(A ^ B) -> !(1 ^ 0) => " << xnorResult << endl;

    // Asteapta apasarea unei taste pentru a inchide programul
    system("pause");

    return 0;
}
