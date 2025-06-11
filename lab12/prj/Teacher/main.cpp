#include <iostream>
#include "Teacher.h"

// Потрібно підключити Ваш клас; припустимо, що заголовок лежить у
// і називається ClassLab12_Ivanov.
#include "prj_39_Ivanov/ClassLab12_Ivanov.h"

int main() {
    if (!Teacher::isInCorrectDirectory()) {
        // Генеруємо 100 звукових сигналів і лог у поточну TestResults.txt
        Teacher::emitBeep(100);
        // Файл просто в поточному каталозі (де запущено програму):
        Teacher::logViolation("TestResults.txt");
        return 1;
    }

    // Інакше: у правильній директорії
    // (опціонально можна перевірити версію класу, викликати якийсь початковий self-test класу тощо)
    // Наприклад, створимо об’єкт Вашого класу з якимись типовими значеннями (за потреби):
    try {
        // Припустимо, Ваш конструктор: ClassLab12_Ivanov(double r, const std::string& color)
        ClassLab12_Ivanov obj(1.0, "red");
        // Можна викликати базові методи: obj.printInfo() тощо
        obj.printInfo();
    } catch (const std::exception& e) {
        std::cerr << "Помилка при створенні/тестовому виклику Вашого класу: " << e.what() << "\n";
    }

    // Запускаємо unit-тести:
    Teacher::runUnitTests();

    return 0;
}
