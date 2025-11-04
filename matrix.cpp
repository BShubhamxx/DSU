#include <iostream>
using namespace std;

class Matrix {
public:
    int m1[3][3], m2[3][3], result[3][3];

    void input() {
        cout << "Enter elements of first 3x3 matrix (m1):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> m1[i][j];
            }
        }

        cout << "Enter elements of second 3x3 matrix (m2):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> m2[i][j];
            }
        }
    }

    void addition() {
        cout << "\nMatrix Addition:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = m1[i][j] + m2[i][j];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void subtraction() {
        cout << "\nMatrix Subtraction:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = m1[i][j] - m2[i][j];
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void multiplication() {
        cout << "\nMatrix Multiplication:\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                result[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    result[i][j] += m1[i][k] * m2[k][j];
                }
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void transpose() {
        cout << "\nTranspose of first matrix (m1^T):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << m1[j][i] << " ";
            }
            cout << endl;
        }

        cout << "\nTranspose of second matrix (m2^T):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << m2[j][i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Matrix mat;
    mat.input();
    mat.addition();
    mat.subtraction();
    mat.multiplication();
    mat.transpose();
    return 0;
}
