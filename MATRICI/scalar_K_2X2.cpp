#include <iostream>
using namespace std;

int main() {
    int A[2][2];
    int K;

    // Citire valori pentru matricea A
    cout << "Introduceți valorile pentru matricea A (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }

    // Citire valoare scalar K
    cout << "Introduceți valoarea scalar K: ";
    cin >> K;

    // Înmulțirea matricei A cu scalarul K
    int result[2][2];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = A[i][j] * K;
        }
    }

    // Afișarea rezultatului
    cout << "\nRezultatul inmultirii matricei A cu scalarul K este:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    system("pause");
    return 0;
}
