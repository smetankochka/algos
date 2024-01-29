#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream file("input.txt");
    if (file) {
        char prevChar = 0;
        char currentChar;
        int maxSeqStart = 1;  // Номер позиции, с которой начинается максимальная подпоследовательность
        int maxSeqLength = 0; // Длина максимальной подпоследовательности
        int currentSeqStart = 1;  // Номер позиции, с которой начинается текущая подпоследовательность
        int currentSeqLength = 1; // Длина текущей подпоследовательности

        while (file.get(currentChar)) {
            if (currentChar > prevChar) {
                currentSeqLength++;
                if (currentSeqLength > maxSeqLength) {
                    maxSeqLength = currentSeqLength;
                    maxSeqStart = currentSeqStart;
                }
            } else {
                currentSeqLength = 1;
                currentSeqStart = file.tellg();
            }
            prevChar = currentChar;
        }
        if (maxSeqLength > 1) {
            std::cout << "наибольшая возрастающая подпоследовательность начинается с позиции: " << maxSeqStart << std::endl;
        } else {
            std::cout << "в файле не найдено возрастающих подпоследовательностей." << std::endl;
        }
    } else {
        std::cerr << "не удалось открыть файл." << std::endl;
    }
    return 0;
}
