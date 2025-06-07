#include <iostream>
#include <string>
#include <vector>
#include <limits>

#include "struct_type_project_8.h"         // Опис PostalRecord
#include "struct_type_project_Kurtiak.h"   // loadData, searchByIndex
#include "struct_type_project_Ivanov.h"    // addRecord, deleteRecord
#include "struct_type_project_Marchenko.h" // printAll, saveAndExit

void printMenu() {
    std::cout << "\n*** Довідник Укрпошти ***\n";
    std::cout << "1. Завантажити дані з файлу" << std::endl;
    std::cout << "2. Пошук за індексом" << std::endl;
    std::cout << "3. Пошук за містом" << std::endl;
    std::cout << "4. Показати всі записи" << std::endl;
    std::cout << "5. Додати запис" << std::endl;
    std::cout << "6. Видалити запис" << std::endl;
    std::cout << "7. Зберегти та вийти" << std::endl;
    std::cout << "Ваш вибір: ";
}

int main() {
    system("chcp 65001 && cls");
    PostalRecord* head = nullptr;
    bool loaded = false;
    int choice;
    std::string file = "data.txt";

    while (true) {
        printMenu();
        std::cin >> choice;
        std::cin.ignore();
        switch (choice) {
            case 1: {
                std::cout << "Введіть назву файлу: "; std::getline(std::cin, file);
                loaded = Kurtiak::loadData(file, head);
                std::cout << (loaded ? "Дані завантажено.\n" : "Не вдалося завантажити файл.\n");
                break;
            }
            case 2: {
                if (!loaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                int idx; std::cout << "Введіть індекс: "; std::cin >> idx;
                auto v = Kurtiak::searchByIndex(head, idx);
                std::cout << "Знайдено " << v.size() << " запис(ів).\n";
                break;
            }
            case 3: {
                if (!loaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                std::string city;
                std::cout << "Введіть назву міста: "; std::getline(std::cin, city);
                std::vector<PostalRecord*> found;
                for (auto* p = head; p; p = p->next)
                    if (p->city == city) found.push_back(p);
                std::cout << "Знайдено " << found.size() << " запис(ів) для " << city << ".\n";
                break;
            }
            case 4:
                if (!loaded) { std::cout << "Спочатку завантажте дані.\n"; break; }
                Marchenko::printAll(head);
                break;
            case 5: {
                PostalRecord r;
                std::cout << "Індекс: "; std::cin >> r.index; std::cin.ignore();
                std::cout << "Область: "; std::getline(std::cin, r.region);
                std::cout << "Район: "; std::getline(std::cin, r.district);
                std::cout << "Місто: "; std::getline(std::cin, r.city);
                std::cout << "ВПЗ: "; std::getline(std::cin, r.postOffice);
                Ivanov::addRecord(head, r);
                std::cout << "Запис додано.\n";
                break;
            }
            case 6: {
                int idx; std::string city;
                std::cout << "Введіть індекс для видалення: "; std::cin >> idx; std::cin.ignore();
                std::cout << "Введіть місто для видалення: "; std::getline(std::cin, city);
                std::cout << (Ivanov::deleteRecord(head, idx, city) ? "Запис видалено.\n" : "Запис не знайдено.\n");
                break;
            }
            case 7:
                Marchenko::saveAndExit(head, file);
                std::cout << "Дані збережено. До побачення!\n";
                return 0;
            default:
                std::cout << "Невірний вибір.\n";
        }
    }
}
