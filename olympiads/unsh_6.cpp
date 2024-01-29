#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main() {
    std::ifstream file("input_unsh_6.txt");
    if (file) {
        char prevChar = 0;
        char currentChar;
        int minSeqStart = 1;  // Номер позиции, с которой начинается максимальная подпоследовательность
        int maxSeqLength = 0; // Длина максимальной подпоследовательности
        int currentSeqStart = 1;  // Номер позиции, с которой начинается текущая подпоследовательность
        int currentSeqLength = 1; // Длина текущей подпоследовательности
        std::string resultabs = "";
        std::string resultrel = "";
        while (file.get(currentChar)) {
            if (currentChar < prevChar) {
                currentSeqLength++;
                resultrel += currentChar;
                if (currentSeqLength > maxSeqLength) {
                    maxSeqLength = currentSeqLength;
                    minSeqStart = currentSeqStart;
                    resultabs = resultrel;  
                }
            } else {
                currentSeqLength = 1;
                resultrel = currentChar;
                currentSeqStart = file.tellg();
            }
            prevChar = currentChar;
        }
        if (maxSeqLength > 1) {
            std::cout << "наибольшая убывающая подпоследовательность имеет длину: " << maxSeqLength << std::endl;
            std::cout << resultabs << std::endl;
        } else {
            std::cout << "в файле не найдено убывающих подпоследовательностей." << std::endl;
        }
    } else {
        std::cerr << "не удалось открыть файл." << std::endl;
    }
    return 0;
}

