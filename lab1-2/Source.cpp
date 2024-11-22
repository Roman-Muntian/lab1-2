#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA");

    srand(time(NULL));

    int A[10];  // Оголошення масиву розміру 10
    int T;
    cout << "Введіть елемент T: ";
    cin >> T;  // Введення елемента T з клавіатури

    // Заповнення масиву випадковими числами від -10 до 10
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 21 - 10;
    }

    // Виведення елементів масиву
    cout << "Елементи масиву: ";
    for (int i = 0; i < 10; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    // Пошук індексу елемента, рівного T
    int indexT = -1;
    for (int i = 0; i < 10; i++) {
        if (A[i] == T) {
            indexT = i;
            break;
        }
    }

    // Якщо елемент T не знайдений
    if (indexT == -1) {
        cout << "Елемент " << T << " не знайдений у масиві." << endl;
    }
    else {
        cout << "Елемент " << T << " знайдений з індексом: " << indexT << endl;

        // Пошук останнього максимального від’ємного елемента правіше за T
        int lastNegativeIndex = -1;
        int maxNegative = -11;

        // Пошук від’ємних елементів правіше за T
        for (int i = indexT + 1; i < 10; i++) {
            if (A[i] < 0) {
                if (A[i] > maxNegative) {
                    maxNegative = A[i];
                    lastNegativeIndex = i;
                }
            }
        }

        // Якщо знайдений останній максимальний від’ємний елемент
        if (lastNegativeIndex != -1) {
            cout << "Останнє максимальне від'ємне число правіше " << T
                << " має значення " << maxNegative
                << " та знаходиться на індексі " << lastNegativeIndex << "." << endl;
        }
        else {
            cout << "Не знайдено жодного від'ємного числа правіше " << T << "." << endl;
        }
    }

    return 0;
}
