#include "Teacher.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>      // ��� system()
#include <filesystem>   // C++17: ��� �������� �� ������ � TestSuite
#include <algorithm>    // ��� ������ �������

namespace fs = std::filesystem;

bool Teacher::isInCorrectDirectory() {
    // __FILE__ ������ ���� �� ����� ����� �� ��� ���������.
    // ���������, �� ������ ������� "Lab12/prj" ��� "Lab12\\prj"
    std::string src = __FILE__;
    // ��� �������� ���������� ����� �� ������ ������� (��� ����� ������ ��������� ��� �������).
    // ��� ������ ������ �������:
    bool ok1 = (src.find("prj/prj_39_Ivanov") != std::string::npos);
    bool ok2 = (src.find("prj\\prj_39_Ivanov") != std::string::npos);
    return ok1 || ok2;
}

void Teacher::emitBeep(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << '\a';
        // ����� ����� �������� �������� ��������, ���� ��������: ���������, std::this_thread::sleep_for(...)
    }
    // ����� ������ ������� �����:
    std::cout << std::flush;
}

void Teacher::logViolation(const std::string& filePath) {
    // �������� ������� ����������� � ���� filePath (������������ ��� ��������� ������)
    std::ofstream ofs(filePath, std::ios::out);
    if (!ofs) {
        std::cerr << "�� ������� ������� ���� ��� ������: " << filePath << "\n";
        return;
    }
    ofs << "���������� ������ ������� ��������� ����������� ������ ��������!";
    ofs.close();
}

std::string Teacher::findLab12Root(const std::string& sourcePath) {
    // ���� ���� ���� ".../Lab12/pri/Teacher.cpp" ��� � backslash �� Windows.
    // ������ ������� "Lab12" � sourcePath:
    const std::string marker = "Lab12";
    auto pos = sourcePath.find(marker);
    if (pos == std::string::npos) {
        return ""; // �� �������� Lab12
    }
    // root ���������� �� ���� "Lab12"
    std::string root = sourcePath.substr(0, pos + marker.size());
    return root;
}

void Teacher::runUnitTests() {
    // 1) ��������� ���� �� TestSuite: �������� ����� Lab12
    std::string src = __FILE__;
    std::string lab12root = findLab12Root(src);
    if (lab12root.empty()) {
        std::cerr << "�� ������� ��������� ����� Lab12 ��� ������� �����.\n";
        return;
    }
    // ������� ���� �� �������� TestSuite
    fs::path testSuiteDir = fs::path(lab12root) / "TestSuite";

    // ������� ���� �� ������������� �����: Lab12/TestSuite/TestResults.txt
    fs::path resultsPath = testSuiteDir / "TestResults.txt";

    // ³������ ���� ���������� �� ��������� (��� ����� ������ Teacher �������� ��������� ���):
    std::ofstream ofs(resultsPath, std::ios::out);
    if (!ofs) {
        std::cerr << "�� ������� ������� ���� ��� ��������� �����: " << resultsPath << "\n";
        return;
    }
    ofs << "=== ���������� unit-���������� ===\n";
    ofs.close();

    // 2) ���������� �� ����� � testSuiteDir, �� ������ ���� ������������ �������.
    // ���������, �� Windows ��������� �� ����������� .exe; �� POSIX � ���������� ����� ���������.
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
            // ���������, �� ���� �� �� ��������� ��� ����������� (owner):
            std::error_code ec;
            auto perms = fs::status(p, ec).permissions();
            if (!ec) {
                if ((perms & fs::perms::owner_exec) != fs::perms::none) {
                    isTestExe = true;
                }
            }
        }

        if (!isTestExe) continue;

        // �������� ������� ��� ������� ����� � ���������������� ������ �� resultsPath
        // �� Windows: "fullpath.exe" >> "...\TestResults.txt" 2>&1
        // �� POSIX ���������
        std::string cmd;
        // ��������� ����� � ����� �� ������� ������
        std::string fullTestPath = p.string();
        std::string resultFileStr = resultsPath.string();
        if (isWindows) {
            cmd = "\"" + fullTestPath + "\" >> \"" + resultFileStr + "\" 2>&1";
        } else {
            cmd = "\"" + fullTestPath + "\" >> \"" + resultFileStr + "\" 2>&1";
        }
        // �������� � ����, �� ����� ���������:
        std::ofstream logofs(resultsPath, std::ios::app);
        if (logofs) {
            logofs << "\n--- ������ �����: " << p.filename().string() << " ---\n";
        }
        // ��������
        int ret = std::system(cmd.c_str());
        if (logofs) {
            logofs << ">> ��������� ���: " << ret << "\n";
            logofs.close();
        }
    }

    std::cout << "Unit-���������� ���������. ���������� � ����: " << resultsPath << "\n";
}
