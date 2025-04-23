#include <iostream>
#include <string>
#include <bitset>
#include <locale.h>

using namespace std;

// �������� 9.1
string seaState(double height) {
    if (height == 0) return "CALM-GLASSY";
    else if (height <= 0.1) return "CALM-RIPPLE";
    else if (height <= 0.5) return "SMOOTH-WAVELET";
    else if (height <= 1.25) return "SLIGHT";
    else if (height <= 2.5) return "MODERATE";
    else if (height <= 4) return "ROUGH";
    else if (height <= 6) return "VERY ROUGH";
    else if (height <= 9) return "HIGH";
    else if (height <= 14) return "VERY HIGH";
    else return "PHENOMENAL";
}

// �������� 9.2
double fahrenheitToCelsius(double tf) {
    return (5.0 / 9.0) * (tf - 32);
}

// �������� 9.3
int countBits(int N, bool countZero) {
    bitset<16> b(N);
    int count = 0;
    for (int i = 0; i < b.size(); i++) {
        if (countZero && b[i] == 0) count++;
        else if (!countZero && b[i] == 1) count++;
    }
    return count;
}

// �������� 9.4
void s_calculation(char symbol) {
    setlocale(LC_CTYPE,"ukr");
    if (symbol == 'j') {
        double h;
        cout << "������ ������ ����� (�): ";
        cin >> h;
        cout << "���� ����: " << seaState(h) << endl;
    } else if (symbol == 'x') {
        double tf;
        cout << "������ ����������� �� �����������: ";
        cin >> tf;
        cout << "����������� �� ������: " << fahrenheitToCelsius(tf) << endl;
    } else if (symbol == 'q') {
        int N;
        cout << "������ ���������� ����� N (�� 65535): ";
        cin >> N;
        cout << "������� ������: 1 � ������ ���, ���� � �������: ";
        int D;
        cin >> D;
        cout << "ʳ������ ���: " << countBits(N, D == 1) << endl;
    } else {
        cout << "������� �������!" << endl;
    }
}

int main() {
    setlocale(LC_CTYPE,"ukr");
    char cmd;
    cout << "������ ������� ('j', 'x', 'q'): ";
    cin >> cmd;
    s_calculation(cmd);
    return 0;
}
