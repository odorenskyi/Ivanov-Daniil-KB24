// ����� ������ ���� ���������
#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

int main() {
    // ��������� ����������
    setlocale(LC_CTYPE,"ukr");
    double x, y, z, S;

    // �������� ������� x, y, z
    cout << "������ x: ";
    cin >> x;
    cout << "������ y: ";
    cin >> y;
    cout << "������ z: ";
    cin >> z;

    // ���������� ������
    S = z * sin(x * x * y) + sqrt(abs(z - 12 * x)) / pow(y, 3);

    // ��������� ����������
    cout << "�������� S = " << S << endl;

    return 0;
}
