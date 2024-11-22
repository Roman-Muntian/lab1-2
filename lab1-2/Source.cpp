#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA");

    srand(time(NULL));

    int A[10];  // ���������� ������ ������ 10
    int T;
    cout << "������ ������� T: ";
    cin >> T;  // �������� �������� T � ���������

    // ���������� ������ ����������� ������� �� -10 �� 10
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 21 - 10;
    }

    // ��������� �������� ������
    cout << "�������� ������: ";
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // ����� ������� ��������, ������ T
    int indexT = -1;
    for (int i = 0; i < 10; i++) {
        if (A[i] == T) {
            indexT = i;
            break;
        }
    }

    // ���� ������� T �� ���������
    if (indexT == -1) {
        cout << "������� " << T << " �� ��������� � �����." << endl;
    }
    else {
        cout << "������� " << T << " ��������� � ��������: " << indexT << endl;

        // ����� ���������� ������������� �䒺����� �������� ������ �� T
        int lastNegativeIndex = -1;
        int maxNegative = -11;

        // ����� �䒺���� �������� ������ �� T
        for (int i = indexT + 1; i < 10; i++) {
            if (A[i] < 0) {
                if (A[i] > maxNegative) {
                    maxNegative = A[i];
                    lastNegativeIndex = i;
                }
            }
        }

        // ���� ��������� ������� ������������ �䒺���� �������
        if (lastNegativeIndex != -1) {
            cout << "������ ����������� ��'���� ����� ������ " << T
                << " �� �������� " << maxNegative
                << " �� ����������� �� ������ " << lastNegativeIndex << "." << endl;
        }
        else {
            cout << "�� �������� ������� ��'������ ����� ������ " << T << "." << endl;
        }
    }

    return 0;
}
