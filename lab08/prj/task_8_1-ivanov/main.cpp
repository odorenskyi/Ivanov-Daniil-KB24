// Автор Іванов Даніїл Андрійович
#include <iostream>
#include <locale>
#include <cmath>

using namespace std;

int main() {
    // Українська локалізація
    setlocale(LC_CTYPE,"ukr");
    double x, y, z, S;

    // Введення значень x, y, z
    cout << "Введіть x: ";
    cin >> x;
    cout << "Введіть y: ";
    cin >> y;
    cout << "Введіть z: ";
    cin >> z;

    // Обчислення виразу
    S = z * sin(x * x * y) + sqrt(abs(z - 12 * x)) / pow(y, 3);

    // Виведення результату
    cout << "Значення S = " << S << endl;

    return 0;
}
