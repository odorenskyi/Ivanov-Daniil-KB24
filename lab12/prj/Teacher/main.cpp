#include <iostream>
#include "Teacher.h"

// ������� ��������� ��� ����; ����������, �� ��������� ������ �
// � ���������� ClassLab12_Ivanov.
#include "prj_39_Ivanov/ClassLab12_Ivanov.h"

int main() {
    if (!Teacher::isInCorrectDirectory()) {
        // �������� 100 �������� ������� � ��� � ������� TestResults.txt
        Teacher::emitBeep(100);
        // ���� ������ � ��������� ������� (�� �������� ��������):
        Teacher::logViolation("TestResults.txt");
        return 1;
    }

    // ������: � ��������� ��������
    // (����������� ����� ��������� ����� �����, ��������� ������ ���������� self-test ����� ����)
    // ���������, �������� �ᒺ�� ������ ����� � ������� �������� ���������� (�� �������):
    try {
        // ����������, ��� �����������: ClassLab12_Ivanov(double r, const std::string& color)
        ClassLab12_Ivanov obj(1.0, "red");
        // ����� ��������� ����� ������: obj.printInfo() ����
        obj.printInfo();
    } catch (const std::exception& e) {
        std::cerr << "������� ��� ��������/��������� ������� ������ �����: " << e.what() << "\n";
    }

    // ��������� unit-�����:
    Teacher::runUnitTests();

    return 0;
}
