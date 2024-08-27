#include <fstream> // Подключаем библиотеку для работы с файлами
#include <vector> // Подключаем библиотеку для работы с векторами

using namespace std; // Используем пространство имен std
using ll = long long; // Сокращаем тип long long до ll

ifstream input("input.txt"); // Открываем файл input.txt для чтения
ofstream output("output.txt"); // Открываем файл output.txt для записи

// Функция для рекурсивной генерации всех перестановок
void permutation(vector<bool> &perm, int n) {
    // Базовый случай: если n = 0, то выводим текущую перестановку
    if (n == 0) {
        for (int i = 0; i < perm.size(); i++) {
            if (perm[i]) { // Если элемент перестановки true
                output << 1; // Выводим 1
            } else { // Иначе
                output << 0; // Выводим 0
            }
        }
        output << "\n"; // Переходим на новую строку
        return; // Возвращаемся
    }
    // Рекурсивный шаг:
    n--; // Уменьшаем n на 1
    perm.push_back(false); // Добавляем false в конец вектора perm
    permutation(perm, n); // Рекурсивно вызываем функцию permutation с уменьшенным n
    perm.back() = true; // Изменяем последний элемент вектора на true
    permutation(perm, n); // Рекурсивно вызываем функцию permutation с уменьшенным n
    perm.pop_back(); // Удаляем последний элемент вектора
    return; // таким образом мы для каждого n вызвали рекрсию два раза, когда последний равен нулю и когда последний равен единице
}

int main() {
    int n;
    input >> n; // Считываем число n из файла input.txt
    vector<bool> perm; // Создаем вектор perm для хранения перестановки
    permutation(perm, n); // Вызываем функцию permutation для генерации перестановок
    input.close(); // Закрываем поток ввода
    output.close(); // Закрываем поток вывода
    return 0; // Возвращаем 0, сигнализируя об успешном выполнении
}
