#include <iostream>
#include <locale.h>

using namespace std;

int main() {
    setlocale(LC_CTYPE,"ukr");
    double waveHeight;
    int grade = -1;

    cout << "Введіть висоту хвилі у футах (FT, не цілі числа писати через крапку): ";
    cin >> waveHeight;

    if (waveHeight == 0)
        grade = 0;
    else if (waveHeight > 0 && waveHeight <= 0.3)
        grade = 1;
    else if (waveHeight > 0.3 && waveHeight <= 1.3)
        grade = 2;
    else if (waveHeight > 1.3 && waveHeight <= 4)
        grade = 3;
    else if (waveHeight > 4 && waveHeight <= 8)
        grade = 4;
    else if (waveHeight > 8 && waveHeight <= 13)
        grade = 5;
    else if (waveHeight > 13 && waveHeight <= 20)
        grade = 6;
    else if (waveHeight > 20 && waveHeight <= 30)
        grade = 7;
    else if (waveHeight > 30 && waveHeight <= 45)
        grade = 8;
    else if (waveHeight > 45)
        grade = 9;

    switch (grade) {
        case 0: cout << "Grade: 0 - CALM-GLASSY";
        break;
        case 1: cout << "Grade: 1 - CALM-RIPPLED";
        break;
        case 2: cout << "Grade: 2 - SMOOTH-WAVELET";
        break;
        case 3: cout << "Grade: 3 - SLIGHT";
        break;
        case 4: cout << "Grade: 4 - MODERATE";
        break;
        case 5: cout << "Grade: 5 - ROUGH";
        break;
        case 6: cout << "Grade: 6 - VERY ROUGH";
        break;
        case 7: cout << "Grade: 7 - HIGH";
        break;
        case 8: cout << "Grade: 8 - VERY HIGH";
        break;
        case 9: cout << "Grade: 9 - PHENOMENAL";
        break;
        default: cout << "Некоректна висота хвилі.";
        break;
    }

    cout << endl;
    return 0;
}
