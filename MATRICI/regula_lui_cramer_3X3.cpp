#include <iostream>
using namespace std;

// Funcție pentru a calcula determinantul unei matrice 3x3
double determinant(double matrix[3][3]) {
    return matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]) -
           matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]) +
           matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
}

int main() {
    // Coeficientii matricei
    double A[3][3];
    double B[3];

    // Introducerea coeficientilor de la utilizator
    cout << "Introduceti coeficientii matricei 3x3:" << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << "Coeficient [rând " << (i + 1) << ", coloană " << (j + 1) << "]: ";
            cin >> A[i][j];
        }
    }

    // Introducerea termenilor liberi
    cout << "Introduceti termenii liberi:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Termen liber [rând " << (i + 1) << "]: ";
        cin >> B[i];
    }

    // Determinantul matricei A
    double D = determinant(A);

    // Matricea D1 pentru x1
    double D1[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            D1[i][j] = (j == 0) ? B[i] : A[i][j]; // Înlocuim prima coloană cu termenii liberi
        }
    }

    // Matricea D2 pentru x2
    double D2[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            D2[i][j] = (j == 1) ? B[i] : A[i][j]; // Înlocuim a doua coloană cu termenii liberi
        }
    }

    // Matricea D3 pentru x3
    double D3[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            D3[i][j] = (j == 2) ? B[i] : A[i][j]; // Înlocuim a treia coloană cu termenii liberi
        }
    }

    // Determinantele D1, D2, D3
    double D1_value = determinant(D1);
    double D2_value = determinant(D2);
    double D3_value = determinant(D3);

    // Calcularea soluțiilor
    if (D != 0) {
        double x1 = D1_value / D;
        double x2 = D2_value / D;
        double x3 = D3_value / D;

        cout << "Soluțiile sistemului sunt:\n";
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
        cout << "x3 = " << x3 << endl;
    } else {
        cout << "Determinantul este 0. Sistemul nu are soluții unice." << endl;
    }
    system("pause");
    return 0;
}
