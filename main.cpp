#include "chip.h"
#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    Chip chipList;

    int choice;
    do {
        cout << "\n===== МЕНЮ =====\n";
        cout << "1. Додати мікросхему\n";
        cout << "2. Вивести всі мікросхеми\n";
        cout << "3. Редагувати мікросхему\n";
        cout << "4. Видалити мікросхему\n";
        cout << "5. Очистити список\n";
        cout << "0. Вихід\n";
        cout << "Ваш вибір: ";

        if (!(cin >> choice)) {
            cout << "❌ Помилка вводу! Введіть число від 0 до 5.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // очистка буфера

        switch (choice) {
        case 1:
            chipList.addChip();
            break;
        case 2:
            chipList.displayChips();
            break;
        case 3:
            chipList.editChip();
            break;
        case 4:
            chipList.removeChip();
            break;
        case 5:
            chipList.clearAll();
            break;
        case 0:
            cout << "Завершення роботи.\n";
            break;
        default:
            cout << "❌ Невірний вибір! Введіть число від 0 до 5.\n";
        }
    } while (choice != 0);

    return 0;
}
