#ifndef CLASSLAB12_IVANOV_H_INCLUDED
#define CLASSLAB12_IVANOV_H_INCLUDED

#include <string>

// ���� ��� ������������� ����� (���) � ���������� �� ��������
class ClassLab12_Ivanov {
private:
    double radius;       // ����� ���
    std::string color;   // ���� (������� ����������� ��������; �� ������� ����� ��������)

    // ��������� ������:
    void validateRadius(double r) const;
    void validateString(const std::string& s, const std::string& fieldName) const;

public:
    // �����������
    ClassLab12_Ivanov(double r, const std::string& clr);

    // ������/������ ������
    double getRadius() const;
    void setRadius(double r);

    // ������/������ �������
    std::string getColor() const;
    void setColor(const std::string& clr);

    // ���������� �ᒺ�� ���
    double getVolume() const;

    // ��������� ����� ��������� (����� ��������������� ��� ������������ ��� ������������)
    void printInfo() const;
};

#endif // CLASSLAB12_IVANOV_H_INCLUDED
