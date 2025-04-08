#include <iostream>
#include <iomanip>
#include <locale>
#include "ivanov.h"

using namespace std;

//�����
ostream& Author(ostream& out) {
    setlocale(LC_CTYPE,"ukr");
    return out << "� ������ ���� ���������";
}

//������� �����
ostream& LogicalExpression(ostream& out, char a, char b) {
    bool result = (a + 1 == b + 2);
    return out << boolalpha << result;
}

//�������� �� ����������
ostream& ValuesAndCalculation(ostream& out, int x, int y, int z) {
    out << "x = " << x << " (0x" << hex << x << dec << ")\n";
    out << "y = " << y << " (0x" << hex << y << dec << ")\n";
    out << "z = " << z << " (0x" << hex << z << dec << ")\n";
    double S = s_calculation(x, y, z);
    out << "S = " << S << "\n";
    return out;
}

int main() {
    setlocale(LC_CTYPE,"ukr");
    int x, y, z;
    char a, b;

    // ���
    cout << "������ x: "; cin >> x;
    cout << "������ y: "; cin >> y;
    cout << "������ z: "; cin >> z;
    cout << "������ ������ a: "; cin >> a;
    cout << "������ ������ b: "; cin >> b;

    // ����
    cout << "8.2.1: " << Author << endl;
    cout << "8.2.2: ";
    LogicalExpression(cout, a, b) << endl;
    cout << "8.2.3:\n";
    ValuesAndCalculation(cout, x, y, z);

    return 0;
}
