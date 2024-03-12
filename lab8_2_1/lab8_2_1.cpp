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

    //���������� ����� ������ ����� �������� n �������� ���������� �� -10 �� 10
    for (int i = 0; i < n; i++) a[i] = float (rand() % 2001 - 1000)/100;

    //�������� ����� �� �����
    cout << "�������� ������: ";
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;

    //�) ������� � ������� ��'����� ��������
    int negative_N = 0;
    float negative_P = 1;

    for (int i = 0; i < n; i++) {
        if (a[i] < 0) {
            negative_N += 1;
            negative_P *= a[i];
        }
    }

    //�������� ��������� �� �����
    cout << "������� ��'����� ��������: " << negative_N << endl;
    cout << "������� ��'����� ��������: " << negative_P << endl;

    //�) ���� �������� ������, ������������ �� ������ � ������ ��������� ����������.
    int positive_N = 0;
    float positive_S = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (positive_N == 1) {    
                positive_S += a[i];
                positive_N = 2;
                break;
            }
            positive_N += 1;
        }
    }

    //�������� ��������� �� �����
    if (positive_N == 2) {
        cout << "���� �������� ��������, ������������ �� ������ � ������ ��������� ����������: " << positive_S;
    } else cout << "�������� �������� ����� ����";
}
