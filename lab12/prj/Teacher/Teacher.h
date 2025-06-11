#ifndef TEACHER_H_INCLUDED
#define TEACHER_H_INCLUDED

#include <string>

class Teacher {
public:
    // Перевіряє, чи під час компіляції main.cpp опрацьовувався із шляху, що містить Lab12/pri
    static bool isInCorrectDirectory();

    // Генерує count звукових сигналів '\a'
    static void emitBeep(int count);

    // Записує у файл filePath повідомлення про порушення
    static void logViolation(const std::string& filePath);

    // Виконує unit-тестування: запускає тести з директорії TestSuite та логуватиме у Lab12/TestSuite/TestResults.txt
    static void runUnitTests();

private:
    // Допоміжні методи для побудови шляхів
    // Наприклад, за шляхом __FILE__ визначити корінь Lab12 і шукати підкаталог TestSuite.
    static std::string findLab12Root(const std::string& sourcePath);
};

#endif // TEACHER_H_INCLUDED
