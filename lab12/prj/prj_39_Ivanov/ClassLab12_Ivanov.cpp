#include "ClassLab12_Ivanov.h"

#include <iostream>     // ��� printInfo �� ��������� ������� � main �� ����� �����
#include <cmath>        // ��� std::pow
#include <stdexcept>    // ��� std::invalid_argument

// ��������� �������� ������
void ClassLab12_Ivanov::validateRadius(double r) const {
    if (r <= 0.0) {
        throw std::invalid_argument("����� �� ���� ������� ������.");
    }
}

// ��������� �������� �������� ���� (���������, ����)
void ClassLab12_Ivanov::validateString(const std::string& s, const std::string& fieldName) const {
    if (s.empty()) {
        throw std::invalid_argument(fieldName + " �� ���� ���� ������� ������.");
    }
}

// ����������� �� ��������� ����� �������
ClassLab12_Ivanov::ClassLab12_Ivanov(double r, const std::string& clr) {
    setRadius(r);
    setColor(clr);
}

// ������ ������
double ClassLab12_Ivanov::getRadius() const {
    return radius;
}

// ������ ������
void ClassLab12_Ivanov::setRadius(double r) {
    validateRadius(r);
    radius = r;
}

// ������ �������
std::string ClassLab12_Ivanov::getColor() const {
    return color;
}

// ������ �������
void ClassLab12_Ivanov::setColor(const std::string& clr) {
    validateString(clr, "Color");
    color = clr;
}

// ���������� �ᒺ�� ���
double ClassLab12_Ivanov::getVolume() const {
    static constexpr double PI = 3.14159265358979323846;
    return 4.0 / 3.0 * PI * std::pow(radius, 3);
}

// ��������� ���������� ��� �ᒺ��
void ClassLab12_Ivanov::printInfo() const {
    std::cout << "ClassLab12_Ivanov object:\n";
    std::cout << "  Radius: " << radius << "\n";
    std::cout << "  Color: " << color << "\n";
    std::cout << "  Volume: " << getVolume() << "\n";
}
