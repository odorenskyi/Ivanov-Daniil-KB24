#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <bitset>
#include <locale.h>

using namespace std;

// Функція підрахунку голосних літер
int countVowels(const string& word) {
    setlocale(LC_CTYPE,"ukr");
    int count = 0;
    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯ";
    for (char ch : word) {
        if (vowels.find(ch) != string::npos)
            count++;
    }
    return count;
}

// Функція підрахунку приголосних літер
int countConsonants(const string& word) {
    setlocale(LC_CTYPE,"ukr");
    int count = 0;
    string vowels = "аеєиіїоуюяАЕЄИІЇОУЮЯ";
    for (char ch : word) {
        if (isalpha(static_cast<unsigned char>(ch)) && vowels.find(ch) == string::npos)
            count++;
    }
    return count;
}

// Приклад функції обчислення
int s_calculation(int x, int y, int z) {
    return x * y + z;  // можна змінити на потрібну логіку
}

int main() {
    setlocale(LC_CTYPE,"ukr");
    string word;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "Не вдалося відкрити файли!" << endl;
        return 1;
    }

    // Зчитування слова з вхідного файлу
    fin >> word;

    // Задача 10.1
    fout << "Автор: Іванов Даніїл Андрійович, ЦНТУ, Кропивницький, Україна, 2025\n";
    fout << "Кількість голосних літер: " << countVowels(word) << endl;

    // Перевірка наявності слова у вірші
    string poem[] = {
        "До щастя не пускає лінощів орава.",
        "У чім воно — ніхто не знає до пуття.",
        "Навчитися радісно робити кожну справу —",
        "Найперше правило щасливого життя."
    };

    bool found = false;
    for (string& line : poem) {
        if (line.find(word) != string::npos) {
            found = true;
            break;
        }
    }

    fout << "Слово \"" << word << "\" "
         << (found ? "є" : "немає")
         << " у вірші Віталія Іващенка.\n";

    // Задача 10.2
    int consonants = countConsonants(word);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    fout << "Кількість приголосних літер: " << consonants << endl;
    fout << "Дата і час: " << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday << " "
         << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

    // Задача 10.3
    int x = 3, y = 4, z = 5, b = 7;
    fout << "s_calculation(" << x << "," << y << "," << z << ") = "
         << s_calculation(x, y, z) << endl;
    fout << "Число " << b << " у двійковому коді: " << bitset<8>(b) << endl;

    fin.close();
    fout.close();

    return 0;
}
