#ifndef CHIP_H
#define CHIP_H

#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct ChipData {
    int id;
    std::string name;
    int pins;
    double voltage;
};

class Chip {
private:
    std::vector<ChipData> chips;

public:
    Chip();
    ~Chip();

    void addChip();               // Додати мікросхему
    void displayChips() const;    // Показати всі
    void removeChip();            // Видалити
    void editChip();              // Редагувати
    void clearAll();              // Очистити все

private:
    bool isValidPins(int pins);
    bool isValidVoltage(double v);

    int getIntInput(const std::string& prompt, int min, int max);
    double getDoubleInput(const std::string& prompt, double min, double max);
    std::string getStringInput(const std::string& prompt);
};

#endif
