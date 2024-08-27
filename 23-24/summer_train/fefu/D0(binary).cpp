#include <fstream>
#include <bitset>

using namespace std;


int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    for (int i = 0; i < (1 << n); i++) { // (1 << n) равносильно 2^n
        // Преобразуем целое число i в двоичное представление
        bitset<32> binary(i); // Используем bitset для удобства
        string binaryString = binary.to_string().substr(32 - n); // Извлекаем n последних бит
        output << binaryString << "\n";
    }

    input.close(); // закрываем потоки чтобы не было утечки
    output.close();

    return 0;
}
