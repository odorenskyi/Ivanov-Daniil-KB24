#include <iostream>
#include <bitset>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE,"ukr");
    unsigned int N;
    cout << "������ ���������� ����� N (�� 0 �� 65535): ";
    cin >> N;

    if (N > 65535) {
        cout << "����� ������� ���� � ����� �� 0 �� 65535." << endl;
        return 1;
    }

    // ���������� �� D1 (����� ������ ������ ��, ���������� � 0)
    bool D1 = (N >> 1) & 1;

    // ���������� N � �������� ������ ��� ��������� ���� �� �������
    bitset<16> binary(N);

    int result = D1 ? (16 - binary.count()) : binary.count(); // ��������� ��������

    cout << "���������: " << result << endl;

    return 0;
}
