#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    string text;
    getline(input, text);  // Читаем первую строку (текст)

    int N;
    input >> N;

    vector<string> words(N);   // Вектор для хранения слов
    for (int i = 0; i < N; ++i) {
        input >> words[i]; // читаем слова в вектор
    }

    vector<int> result(N); // Вектор для хранения результата
    for (int i = 0; i < N; ++i) {
        if (text.find(words[i]) != string::npos) { // просто есть ли слово в тексте с помощью встроенной функции 
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }

    for (int i = 0; i < N; ++i) {
        output << result[i] << " "; // записываем результат
    }

    input.close();
    output.close();

    return 0;
}
