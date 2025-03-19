#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    std::vector<std::string> mas;
    std::string x;
    while (std::getline(std::cin, x)) {
        mas.push_back(x);
    }
    sort(mas.rbegin(), mas.rend());
    for (std::string y : mas) {
        std::cout << y << "\n";
    }
}