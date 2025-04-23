#include <iostream>
#include <bitset>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE,"ukr");
    unsigned int N;
    cout << "Введіть натуральне число N (від 0 до 65535): ";
    cin >> N;

    if (N > 65535) {
        cout << "Число повинно бути в межах від 0 до 65535." << endl;
        return 1;
    }

    // Перевіряємо біт D1 (тобто другий справа біт, індексація з 0)
    bool D1 = (N >> 1) & 1;

    // Конвертуємо N в двійковий вигляд для підрахунку нулів та одиниць
    bitset<16> binary(N);

    int result = D1 ? (16 - binary.count()) : binary.count(); // тернарний оператор

    cout << "Результат: " << result << endl;

    return 0;
}
