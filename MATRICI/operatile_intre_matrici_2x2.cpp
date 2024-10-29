#include <iostream>
using namespace std;

int main() {
    int A[2][2], B[2][2];
    int sum[2][2], diff[2][2], prod[2][2];
    
    // Citire valori pentru matricea A
    cout << "Introduceți valorile pentru matricea A (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "A[" << i+1 << "][" << j+1 << "]: ";
            cin >> A[i][j];
        }
    }
    
    // Citire valori pentru matricea B
    cout << "\nIntroduceți valorile pentru matricea B (2x2):\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << "B[" << i+1 << "][" << j+1 << "]: ";
            cin >> B[i][j];
        }
    }

    // Adunarea matricilor A + B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            sum[i][j] = A[i][j] + B[i][j];
        }
    }

    // Scăderea matricilor A - B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            diff[i][j] = A[i][j] - B[i][j];
        }
    }

    // Înmulțirea matricilor A * B
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            prod[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                prod[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Afișarea rezultatelor
    cout << "\nSuma matricilor A + B:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nDiferenta matricilor A - B:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << diff[i][j] << " ";
        }
        cout << endl;
    }

    cout << "\nProdusul matricilor A * B:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << prod[i][j] << " ";
        }
        cout << endl;
    }
    
    system("pause");
    
    return 0;
}
