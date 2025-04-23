#include <iostream>
#include <string>
#include <bitset>
#include <locale.h>

using namespace std;

// Завдання 9.1
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

// Завдання 9.2
double fahrenheitToCelsius(double tf) {
    return (5.0 / 9.0) * (tf - 32);
}

// Завдання 9.3
int countBits(int N, bool countZero) {
    bitset<16> b(N);
    int count = 0;
    for (int i = 0; i < b.size(); i++) {
        if (countZero && b[i] == 0) count++;
        else if (!countZero && b[i] == 1) count++;
    }
    return count;
}

// Завдання 9.4
void s_calculation(char symbol) {
    setlocale(LC_CTYPE,"ukr");
    if (symbol == 'j') {
        double h;
        cout << "Введіть висоту хвиль (м): ";
        cin >> h;
        cout << "Стан моря: " << seaState(h) << endl;
    } else if (symbol == 'x') {
        double tf;
        cout << "Введіть температуру за Фаренгейтом: ";
        cin >> tf;
        cout << "Температура за Цельсієм: " << fahrenheitToCelsius(tf) << endl;
    } else if (symbol == 'q') {
        int N;
        cout << "Введіть натуральне число N (до 65535): ";
        cin >> N;
        cout << "Виберіть варіант: 1 — рахуємо нулі, інше — одиниці: ";
        int D;
        cin >> D;
        cout << "Кількість бітів: " << countBits(N, D == 1) << endl;
    } else {
        cout << "Невідома команда!" << endl;
    }
}

int main() {
    setlocale(LC_CTYPE,"ukr");
    char cmd;
    cout << "Введіть команду ('j', 'x', 'q'): ";
    cin >> cmd;
    s_calculation(cmd);
    return 0;
}
