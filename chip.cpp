#include "chip.h"
using namespace std;

Chip::Chip() {
    cout << "Об'єкт класу Chip створено.\n";
}

Chip::~Chip() {
    cout << "Об'єкт класу Chip знищено.\n";
}

bool Chip::isValidPins(int pins) {
    return pins > 0 && pins <= 200;
}

bool Chip::isValidVoltage(double v) {
    return v >= 0.5 && v <= 20.0;
}

int Chip::getIntInput(const string& prompt, int min, int max) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "❌ Помилка! Введіть число від " << min << " до " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

double Chip::getDoubleInput(const string& prompt, double min, double max) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "❌ Помилка! Введіть число від " << min << " до " << max << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string Chip::getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    while (value.empty()) {
        cout << "❌ Рядок не може бути порожнім! Спробуйте ще раз: ";
        getline(cin, value);
    }
    return value;
}

void Chip::addChip() {
    ChipData newChip;
    cout << "\n=== Додавання мікросхеми ===\n";

    newChip.id = getIntInput("Введіть ID мікросхеми (1–9999): ", 1, 9999);
    newChip.name = getStringInput("Введіть назву/маркування: ");
    newChip.pins = getIntInput("Введіть кількість виводів (1–200): ", 1, 200);
    newChip.voltage = getDoubleInput("Введіть напругу живлення (0.5–20 В): ", 0.5, 20.0);

    chips.push_back(newChip);
    cout << "✅ Мікросхему успішно додано!\n";
}

void Chip::displayChips() const {
    if (chips.empty()) {
        cout << "\nСписок мікросхем порожній.\n";
        return;
    }

    cout << "\n=== Список мікросхем ===\n";
    for (size_t i = 0; i < chips.size(); ++i) {
        const auto& chip = chips[i];
        cout << i + 1 << ". ID: " << chip.id
             << " | Назва: " << chip.name
             << " | Виводи: " << chip.pins
             << " | Напруга: " << chip.voltage << " В\n";
    }
}

void Chip::removeChip() {
    if (chips.empty()) {
        cout << "\nСписок порожній.\n";
        return;
    }

    int id = getIntInput("Введіть ID мікросхеми для видалення: ", 1, 9999);
    for (auto it = chips.begin(); it != chips.end(); ++it) {
        if (it->id == id) {
            chips.erase(it);
            cout << "✅ Мікросхему з ID " << id << " видалено.\n";
            return;
        }
    }
    cout << "❌ Мікросхему з таким ID не знайдено.\n";
}

void Chip::editChip() {
    if (chips.empty()) {
        cout << "\nСписок порожній.\n";
        return;
    }

    int id = getIntInput("Введіть ID мікросхеми для редагування: ", 1, 9999);
    for (auto& chip : chips) {
        if (chip.id == id) {
            cout << "\n=== Редагування мікросхеми ===\n";
            chip.name = getStringInput("Нова назва/маркування: ");
            chip.pins = getIntInput("Нова кількість виводів (1–200): ", 1, 200);
            chip.voltage = getDoubleInput("Нова напруга живлення (0.5–20 В): ", 0.5, 20.0);
            cout << "✅ Дані оновлено!\n";
            return;
        }
    }
    cout << "❌ Мікросхему не знайдено.\n";
}

void Chip::clearAll() {
    chips.clear();
    cout << "✅ Усі дані очищено.\n";
}

void Chip::insertChip() {
    cout << "\n=== Вставка мікросхеми у довільне місце ===\n";

    if (chips.empty()) {
        cout << "Список порожній — мікросхема буде додана як перша.\n";
    }

    int position = getIntInput("Вкажіть позицію для вставки (1–" + to_string(chips.size() + 1) + "): ", 1, chips.size() + 1);

    ChipData newChip;
    newChip.id = getIntInput("Введіть ID мікросхеми (1–9999): ", 1, 9999);
    newChip.name = getStringInput("Введіть назву/маркування: ");
    newChip.pins = getIntInput("Введіть кількість виводів (1–200): ", 1, 200);
    newChip.voltage = getDoubleInput("Введіть напругу живлення (0.5–20 В): ", 0.5, 20.0);

    chips.insert(chips.begin() + (position - 1), newChip);
    cout << "✅ Мікросхему вставлено у позицію " << position << ".\n";
}

void Chip::swapChips() {
    cout << "\n=== Обмін двох мікросхем ===\n";

    if (chips.size() < 2) {
        cout << "❌ Недостатньо елементів для обміну (потрібно мінімум 2).\n";
        return;
    }

    int first = getIntInput("Введіть позицію першої мікросхеми (1–" + to_string(chips.size()) + "): ", 1, chips.size());
    int second = getIntInput("Введіть позицію другої мікросхеми (1–" + to_string(chips.size()) + "): ", 1, chips.size());

    if (first == second) {
        cout << "⚠️ Позиції збігаються — обмін не потрібен.\n";
        return;
    }

    swap(chips[first - 1], chips[second - 1]);
    cout << "✅ Мікросхеми на позиціях " << first << " і " << second << " успішно обміняні!\n";
}
