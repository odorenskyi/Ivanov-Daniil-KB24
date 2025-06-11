#include <iostream>
#include "ClassLab12_Ivanov.h"

int main() {
    system("chcp 1251 && cls");
    try {
        // Приклад створення об'єкта; замініть назву на вашу назву класу, якщо змінили:
        ClassLab12_Ivanov ball(5.0, "blue");

        std::cout << "Початкові значення:\n";
        ball.printInfo();

        // Запит на новий радіус
        double newRadius;
        std::cout << "Введіть новий радіус: ";
        if (std::cin >> newRadius) {
            try {
                ball.setRadius(newRadius);
                std::cout << "Після зміни радіуса:\n";
                ball.printInfo();
            } catch (const std::exception& e) {
                std::cerr << "Помилка при встановленні радіуса: " << e.what() << "\n";
            }
        }

        // Запит на новий колір
        std::string newColor;
        std::cout << "Введіть новий колір: ";
        if (std::cin >> newColor) {
            try {
                ball.setColor(newColor);
                std::cout << "Після зміни кольору:\n";
                ball.printInfo();
            } catch (const std::exception& e) {
                std::cerr << "Помилка при встановленні кольору: " << e.what() << "\n";
            }
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Помилка при створенні об'єкта: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
