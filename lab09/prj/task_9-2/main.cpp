#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE,"ukr");
    double tf, tc;

    // ��� ����������� �� ������ ����������
    cout << "������ ����������� � �����������: ";
    cin >> tf;

    // ���������� ����������� � �������
    tc = 5.0 / 9.0 * (tf - 32);

    // ���� ����������
    cout << "����������� � �������: " << tc << endl;

    return 0;
}
