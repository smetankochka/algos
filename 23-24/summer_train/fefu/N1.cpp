#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
  ifstream input("input.txt"); // создаем поток input из выходного файла
  ofstream output("output.txt"); 

  string str1, str2;
  getline(input, str1); // getline читает строку из потока в переменную (input - поток, str1 - строка куда читаем)
  getline(input, str2);

  size_t pos = str1.find(str2); // встроенная функция ищет позицию первого вхождения

  if (pos != string::npos) { // если позиция имеет тип нан (string::npos) то значит вхождения вообще нет
    output << pos + 1; // добавляем один типо индексация с единички
  } else {
    output << -1; // если не нашли пишем -1
  }

  input.close(); // закрываем потоки чтобы не было утечки
  output.close();

  return 0;
}
