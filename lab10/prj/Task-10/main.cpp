#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cctype>
#include <bitset>
#include <locale.h>

using namespace std;

// ������� ��������� �������� ����
int countVowels(const string& word) {
    setlocale(LC_CTYPE,"ukr");
    int count = 0;
    string vowels = "��賿�����ŪȲ�����";
    for (char ch : word) {
        if (vowels.find(ch) != string::npos)
            count++;
    }
    return count;
}

// ������� ��������� ����������� ����
int countConsonants(const string& word) {
    setlocale(LC_CTYPE,"ukr");
    int count = 0;
    string vowels = "��賿�����ŪȲ�����";
    for (char ch : word) {
        if (isalpha(static_cast<unsigned char>(ch)) && vowels.find(ch) == string::npos)
            count++;
    }
    return count;
}

// ������� ������� ����������
int s_calculation(int x, int y, int z) {
    return x * y + z;  // ����� ������ �� ������� �����
}

int main() {
    setlocale(LC_CTYPE,"ukr");
    string word;
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin.is_open() || !fout.is_open()) {
        cerr << "�� ������� ������� �����!" << endl;
        return 1;
    }

    // ���������� ����� � �������� �����
    fin >> word;

    // ������ 10.1
    fout << "�����: ������ ���� ���������, ����, �������������, ������, 2025\n";
    fout << "ʳ������ �������� ����: " << countVowels(word) << endl;

    // �������� �������� ����� � ����
    string poem[] = {
        "�� ����� �� ����� ������ �����.",
        "� ��� ���� � ���� �� ��� �� �����.",
        "��������� ������ ������ ����� ������ �",
        "�������� ������� ��������� �����."
    };

    bool found = false;
    for (string& line : poem) {
        if (line.find(word) != string::npos) {
            found = true;
            break;
        }
    }

    fout << "����� \"" << word << "\" "
         << (found ? "�" : "����")
         << " � ���� ³���� ��������.\n";

    // ������ 10.2
    int consonants = countConsonants(word);
    time_t now = time(0);
    tm* ltm = localtime(&now);
    fout << "ʳ������ ����������� ����: " << consonants << endl;
    fout << "���� � ���: " << 1900 + ltm->tm_year << "-"
         << 1 + ltm->tm_mon << "-"
         << ltm->tm_mday << " "
         << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

    // ������ 10.3
    int x = 3, y = 4, z = 5, b = 7;
    fout << "s_calculation(" << x << "," << y << "," << z << ") = "
         << s_calculation(x, y, z) << endl;
    fout << "����� " << b << " � ��������� ���: " << bitset<8>(b) << endl;

    fin.close();
    fout.close();

    return 0;
}
