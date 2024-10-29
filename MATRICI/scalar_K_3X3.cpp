#include <iostream>
using namespace std;

int main() {
    int A[3][3];
    int K;

    // Citire valori pentru matricea A
    cout << "Introduceți valorile pentru matricea A (3x3):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Citire valoare scalar K
    cout << "Introduceți valoarea scalar K: ";
    cin >> K;

    // Înmulțirea matricei A cu scalarul K
    int result[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = A[i][j] * K;
        }
    }

    // Afișarea rezultatului
    cout << "\nRezultatul inmulțirii matricei A cu scalarul K este:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
