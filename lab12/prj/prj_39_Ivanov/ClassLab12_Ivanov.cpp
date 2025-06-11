#include "ClassLab12_Ivanov.h"

#include <iostream>     // для printInfo та виведення помилок у main чи інших місцях
#include <cmath>        // для std::pow
#include <stdexcept>    // для std::invalid_argument

// Реалізація валідації радіуса
void ClassLab12_Ivanov::validateRadius(double r) const {
    if (r <= 0.0) {
        throw std::invalid_argument("Радіус має бути додатнім числом.");
    }
}

// Реалізація валідації рядкових полів (наприклад, колір)
void ClassLab12_Ivanov::validateString(const std::string& s, const std::string& fieldName) const {
    if (s.empty()) {
        throw std::invalid_argument(fieldName + " не може бути порожнім рядком.");
    }
}

// Конструктор із валідацією через сеттери
ClassLab12_Ivanov::ClassLab12_Ivanov(double r, const std::string& clr) {
    setRadius(r);
    setColor(clr);
}

// Геттер радіуса
double ClassLab12_Ivanov::getRadius() const {
    return radius;
}

// Сеттер радіуса
void ClassLab12_Ivanov::setRadius(double r) {
    validateRadius(r);
    radius = r;
}

// Геттер кольору
std::string ClassLab12_Ivanov::getColor() const {
    return color;
}

// Сеттер кольору
void ClassLab12_Ivanov::setColor(const std::string& clr) {
    validateString(clr, "Color");
    color = clr;
}

// Обчислення об’єму кулі
double ClassLab12_Ivanov::getVolume() const {
    static constexpr double PI = 3.14159265358979323846;
    return 4.0 / 3.0 * PI * std::pow(radius, 3);
}

// Виведення інформації про об’єкт
void ClassLab12_Ivanov::printInfo() const {
    std::cout << "ClassLab12_Ivanov object:\n";
    std::cout << "  Radius: " << radius << "\n";
    std::cout << "  Color: " << color << "\n";
    std::cout << "  Volume: " << getVolume() << "\n";
}
