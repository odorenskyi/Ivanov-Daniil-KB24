#ifndef CLASSLAB12_IVANOV_H_INCLUDED
#define CLASSLAB12_IVANOV_H_INCLUDED

#include <string>

// Клас для представлення сфери (кулі) з атрибутами та методами
class ClassLab12_Ivanov {
private:
    double radius;       // радіус кулі
    std::string color;   // колір (приклад додаткового атрибута; за потреби можна видалити)

    // Валідаційні методи:
    void validateRadius(double r) const;
    void validateString(const std::string& s, const std::string& fieldName) const;

public:
    // Конструктор
    ClassLab12_Ivanov(double r, const std::string& clr);

    // Геттер/Сеттер радіуса
    double getRadius() const;
    void setRadius(double r);

    // Геттер/Сеттер кольору
    std::string getColor() const;
    void setColor(const std::string& clr);

    // Обчислення об’єму кулі
    double getVolume() const;

    // Допоміжний метод виведення (можна використовувати для налагодження або демонстрації)
    void printInfo() const;
};

#endif // CLASSLAB12_IVANOV_H_INCLUDED
