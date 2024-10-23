#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Definirea structurii Persoana
struct Persoana {
    string nume;
    int varsta;
    string adresa;
};

// Funcție pentru a adăuga o persoană în vector
void adaugaPersoana(vector<Persoana>& persoane) {
    Persoana p;
    cout << "Introduceti numele: ";
    cin >> p.nume;
    cout << "Introduceti varsta: ";
    cin >> p.varsta;
    cout << "Introduceti adresa: ";
    cin.ignore(); // Curățăm buffer-ul pentru a putea citi linia completă
    getline(cin, p.adresa); // Citim linia completă pentru adresa

    persoane.push_back(p); // Adăugăm persoana în vector
}

// Funcție pentru a afișa informațiile despre toate persoanele
void afiseazaPersoane(const vector<Persoana>& persoane) {
    cout << "\nLista persoanelor:\n";
    for (const auto& p : persoane) {
        cout << "Nume: " << p.nume << ", Varsta: " << p.varsta << ", Adresa: " << p.adresa << endl;
    }
}

int main() {
    vector<Persoana> persoane; // Vector pentru a stoca persoanele
    int numarPersoane;

    cout << "Cate persoane doriti sa introduceti? ";
    cin >> numarPersoane;

    for (int i = 0; i < numarPersoane; ++i) {
        cout << "\nIntroduceti detaliile persoanei " << (i + 1) << ":\n";
        adaugaPersoana(persoane);
    }

    afiseazaPersoane(persoane); // Afișăm persoanele introduse
    system("pause");
    return 0;
}
