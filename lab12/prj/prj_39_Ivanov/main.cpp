#include <iostream>
#include "ClassLab12_Ivanov.h"

int main() {
    system("chcp 1251 && cls");
    try {
        // ������� ��������� ��'����; ������ ����� �� ���� ����� �����, ���� ������:
        ClassLab12_Ivanov ball(5.0, "blue");

        std::cout << "�������� ��������:\n";
        ball.printInfo();

        // ����� �� ����� �����
        double newRadius;
        std::cout << "������ ����� �����: ";
        if (std::cin >> newRadius) {
            try {
                ball.setRadius(newRadius);
                std::cout << "ϳ��� ���� ������:\n";
                ball.printInfo();
            } catch (const std::exception& e) {
                std::cerr << "������� ��� ����������� ������: " << e.what() << "\n";
            }
        }

        // ����� �� ����� ����
        std::string newColor;
        std::cout << "������ ����� ����: ";
        if (std::cin >> newColor) {
            try {
                ball.setColor(newColor);
                std::cout << "ϳ��� ���� �������:\n";
                ball.printInfo();
            } catch (const std::exception& e) {
                std::cerr << "������� ��� ����������� �������: " << e.what() << "\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "������� ��� �������� ��'����: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
