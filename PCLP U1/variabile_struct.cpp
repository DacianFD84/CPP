#include <iostream>

// Definim o structură pentru a reprezenta o persoană
struct Persoana {
    std::string nume;
    int varsta;
    double inaltime;
};

int main() {
    Persoana p;  // Variabilă de tip struct

    // Inițializăm câmpurile structurii
    p.nume = "Andrei";
    p.varsta = 25;
    p.inaltime = 1.75;

    // Afișăm datele despre persoană
    std::cout << "Nume: " << p.nume << std::endl;
    std::cout << "Varsta: " << p.varsta << std::endl;
    std::cout << "Inaltime: " << p.inaltime << "m" << std::endl;
    system("pause");
    return 0;
}
