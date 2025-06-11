#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include <string>

class Teacher {
public:
    // ��������, �� �� ��� ��������� main.cpp �������������� �� �����, �� ������ Lab12/pri
    static bool isInCorrectDirectory();

    // ������ count �������� ������� '\a'
    static void emitBeep(int count);

    // ������ � ���� filePath ����������� ��� ���������
    static void logViolation(const std::string& filePath);

    // ������ unit-����������: ������� ����� � �������� TestSuite �� ���������� � Lab12/TestSuite/TestResults.txt
    static void runUnitTests();

private:
    // ������� ������ ��� �������� ������
    // ���������, �� ������ __FILE__ ��������� ����� Lab12 � ������ ��������� TestSuite.
    static std::string findLab12Root(const std::string& sourcePath);
};

#endif // TEACHER_H_INCLUDED
