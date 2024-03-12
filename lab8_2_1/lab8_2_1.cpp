#include <iostream>
#include "windows.h"
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int n = 20;
    float a[n];

    srand(time(NULL));

    //Ініціалізуємо масив дійсних чисел довжиною n елементів значеннями від -10 до 10
    for (int i = 0; i < n; i++) a[i] = float (rand() % 2001 - 1000)/100;

    //Виводимо масив на екран
    cout << "Елементи масиву: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    //а) кількість і добуток від'ємних елементів
    int negative_N = 0;
    float negative_P = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negative_N++;
            negative_P *= a[i];
        }
    }

    //Виводимо результат на екран
    cout << "кількість від'ємних елементів: " << negative_N << endl;
    cout << "добуток від'ємних елементів: " << negative_P << endl;

    //б) сума елементів масиву, розташованих між першим і другим додатними елементами.
    int positive_N = 0;
    float positive_S = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            positive_N++;
            if (positive_N == 2) break;
        }
        if (positive_N == 1) positive_S += a[i];
    }

    //Виводимо результат на екран
    if (positive_N == 2) {
        cout << "Сума додатних елементів, розташованих між першим і другим додатними елементами: " << positive_S;
    } else cout << "Додатних елементів менше двох";
}
