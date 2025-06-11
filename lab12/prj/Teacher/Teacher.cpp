#include "Teacher.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>      // для system()
#include <filesystem>   // C++17: для ітерації по файлах у TestSuite
#include <algorithm>    // для пошуку підрядків

namespace fs = std::filesystem;

bool Teacher::isInCorrectDirectory() {
    // __FILE__ містить шлях до цього файлу під час компіляції.
    // Перевіримо, чи містить підрядок "Lab12/prj" або "Lab12\\prj"
    std::string src = __FILE__;
    // Для зручності переведемо слеші до одного формату (але можна просто перевіряти два варіанти).
    // Тут шукаємо обидва варіанти:
    bool ok1 = (src.find("prj/prj_39_Ivanov") != std::string::npos);
    bool ok2 = (src.find("prj\\prj_39_Ivanov") != std::string::npos);
    return ok1 || ok2;
}

void Teacher::emitBeep(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << '\a';
        // Можна також вставити невелику затримку, якщо хочеться: наприклад, std::this_thread::sleep_for(...)
    }
    // Можна відразу скинути буфер:
    std::cout << std::flush;
}

void Teacher::logViolation(const std::string& filePath) {
    // Записуємо вказане повідомлення у файл filePath (перезаписуємо або створюємо заново)
    std::ofstream ofs(filePath, std::ios::out);
    if (!ofs) {
        std::cerr << "Не вдалося відкрити файл для запису: " << filePath << "\n";
        return;
    }
    ofs << "Встановлені вимоги порядку виконання лабораторної роботи порушено!";
    ofs.close();
}

std::string Teacher::findLab12Root(const std::string& sourcePath) {
    // Маємо шлях типу ".../Lab12/pri/Teacher.cpp" або з backslash на Windows.
    // Шукаємо підрядок "Lab12" у sourcePath:
    const std::string marker = "Lab12";
    auto pos = sourcePath.find(marker);
    if (pos == std::string::npos) {
        return ""; // не знайдено Lab12
    }
    // root включатиме до кінця "Lab12"
    std::string root = sourcePath.substr(0, pos + marker.size());
    return root;
}

void Teacher::runUnitTests() {
    // 1) визначимо шлях до TestSuite: знайдемо корінь Lab12
    std::string src = __FILE__;
    std::string lab12root = findLab12Root(src);
    if (lab12root.empty()) {
        std::cerr << "Не вдалося визначити корінь Lab12 для запуску тестів.\n";
        return;
    }
    // Формуємо шлях до каталогу TestSuite
    fs::path testSuiteDir = fs::path(lab12root) / "TestSuite";

    // Формуємо шлях до результатного файлу: Lab12/TestSuite/TestResults.txt
    fs::path resultsPath = testSuiteDir / "TestResults.txt";

    // Відкриємо файл результатів на перезапис (щоб кожен запуск Teacher очищував попередній лог):
    std::ofstream ofs(resultsPath, std::ios::out);
    if (!ofs) {
        std::cerr << "Не вдалося відкрити файл для логування тестів: " << resultsPath << "\n";
        return;
    }
    ofs << "=== Результати unit-тестування ===\n";
    ofs.close();

    // 2) Переберемо всі файли у testSuiteDir, які можуть бути виконуваними тестами.
    // Наприклад, на Windows фільтруємо за розширенням .exe; на POSIX — перевіряємо права виконання.
    bool isWindows =
    #ifdef _WIN32
        true;
    #else
        false;
    #endif

    for (auto const& entry : fs::directory_iterator(testSuiteDir)) {
        if (!entry.is_regular_file()) continue;
        fs::path p = entry.path();
        bool isTestExe = false;
        if (isWindows) {
            if (p.extension() == ".exe") {
                isTestExe = true;
            }
        } else {
            // Перевіримо, чи файл має біт виконання для користувача (owner):
            std::error_code ec;
            auto perms = fs::status(p, ec).permissions();
            if (!ec) {
                if ((perms & fs::perms::owner_exec) != fs::perms::none) {
                    isTestExe = true;
                }
            }
        }

        if (!isTestExe) continue;

        // Сформуємо команду для запуску тесту з перенаправленням виводу до resultsPath
        // На Windows: "fullpath.exe" >> "...\TestResults.txt" 2>&1
        // На POSIX аналогічно
        std::string cmd;
        // Обгортаємо шляхи в лапки на випадок пробілів
        std::string fullTestPath = p.string();
        std::string resultFileStr = resultsPath.string();
        if (isWindows) {
            cmd = "\"" + fullTestPath + "\" >> \"" + resultFileStr + "\" 2>&1";
        } else {
            cmd = "\"" + fullTestPath + "\" >> \"" + resultFileStr + "\" 2>&1";
        }
        // Записати у логи, що зараз запускаємо:
        std::ofstream logofs(resultsPath, std::ios::app);
        if (logofs) {
            logofs << "\n--- Запуск тесту: " << p.filename().string() << " ---\n";
        }
        // Виконати
        int ret = std::system(cmd.c_str());
        if (logofs) {
            logofs << ">> Повернено код: " << ret << "\n";
            logofs.close();
        }
    }

    std::cout << "Unit-тестування завершено. Результати в файлі: " << resultsPath << "\n";
}
