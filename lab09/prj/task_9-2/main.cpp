#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE,"ukr");
    double tf, tc;

    // Ввід температури за шкалою Фаренгейта
    cout << "Введіть температуру у Фаренгейтах: ";
    cin >> tf;

    // Обчислення температури у Цельсіях
    tc = 5.0 / 9.0 * (tf - 32);

    // Вивід результату
    cout << "Температура у Цельсіях: " << tc << endl;

    return 0;
}
