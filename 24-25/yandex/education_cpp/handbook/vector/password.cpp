#include <iostream>
#include <string>

int main() {
    std::string s;
    std::cin >> s;
    bool flag = true;
    int up_symb = 0, low_symb = 0, numbers = 0, other_symb = 0;
    for (char c : s) {
        if (c < 33 || c > 126) {
            flag = false;
        }
        if (c >= '0' && c <= '9') {
            numbers = 1;
        } else if (c >= 'A' && c <= 'Z') {
            up_symb = 1;
        } else if (c >= 'a' && c <= 'z') {
            low_symb = 1;
        } else {
            other_symb = 1;
        }
    }
    if (s.size() >= 8 && s.size() <= 14 && numbers + up_symb + low_symb + other_symb >= 3 && flag) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}