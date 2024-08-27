#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

// Функция для проверки, имеют ли два числа одинаковое количество цифр
bool have_same_digits(int num1, int num2) {
    int digits1 = 0;
    int digits2 = 0;
    while (num1 > 0) {
        digits1++;
        num1 /= 10;
    }
    while (num2 > 0) {
        digits2++;
        num2 /= 10;
    }
    return digits1 == digits2;
}

// Функция для проверки, является ли пара чисел (x, y) допустимой
bool is_valid(int x, int y, int c, int f, int s) {
    return x + y == c && have_same_digits(x, f) && have_same_digits(y, s);
}

// Функция для генерации перестановки цифр числа
vector<int> generate_permutations(int num) {
    vector<int> permutations;
    vector<int> digits;
    while (num > 0) {
        digits.push_back(num % 10);
        num /= 10;
    }
    sort(digits.begin(), digits.end());
    do {
        long long current_permutation = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            current_permutation = current_permutation * 10 + digits[i];
        }
        permutations.push_back(current_permutation);
    } while (next_permutation(digits.begin(), digits.end()));
    return permutations;
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int a, b, c;
    input >> a >> b >> c;

    // Создаем хеш-таблицу для быстрого поиска перестановок числа a
    unordered_map<int, bool> permutations_a;
    for (int x : generate_permutations(a)) {
        permutations_a[x] = true;
    }

    // Проверяем все перестановки числа b
    for (int y : generate_permutations(b)) {
        // Проверяем, есть ли в хеш-таблице перестановка x, удовлетворяющая условию is_valid
        int x = c - y;
        if (permutations_a.count(x) && is_valid(x, y, c, a, b)) {
            output << "YES" << "\n";
            output << x << " " << y << "\n";
            return 0;
        }
    }

    output << "NO" << "\n";

    input.close();
    output.close();
    return 0;
}
// Ускорения:

// 1. Использование хеш-таблицы:  Вместо перебора всех пар перестановок из a и b, мы создаем хеш-таблицу для перестановок a. Это позволяет нам за O(1) проверить, существует ли перестановка x, удовлетворяющая условию is_valid.

// 2. Ранняя проверка:  Вместо того чтобы перебирать все перестановки b и затем проверять is_valid, мы сначала вычисляем x = c - y и проверяем, существует ли такая перестановка в хеш-таблице. Если нет, мы не тратим время на вызов is_valid.

// Преимущества:

// * Снижение времени выполнения:  Хеш-таблица обеспечивает быстрый доступ к данным, что позволяет сократить время поиска.
// * Уменьшение числа вызовов is_valid: Ранняя проверка позволяет избежать вызова is_valid для пар, которые заведомо не удовлетворяют условию.
