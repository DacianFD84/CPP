#include <iostream>
using namespace std;

int main() {
    int A[3][3];

    // Citire valori pentru matricea A
    cout << "Introduceți valorile pentru matricea A (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Calcularea transpusei
    int transposed[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transposed[j][i] = A[i][j];
        }
    }

    // Afișarea matricei transposed
    cout << "\nTranspusa matricei A este:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << transposed[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
