#include <iostream>
#include <string>

int main() {
    std::string s_input;
    std::string s_result = "";
    std::cin >> s_input;
    s_result += s_input[0];
    for (size_t i = 1; i != s_input.size(); ++i) {
        char x = s_input[i];

        if (x == 'a' || x == 'e' || x == 'h' || x == 'i' || x == 'o' || x == 'u' || x == 'w' || x == 'y') {
            continue;
        }

        char cur = '2';
        if (x == 'b' || x == 'f' || x == 'p' || x == 'v') {
            cur = '1';
        } else if (x == 'd' || x == 't') {
            cur = '3';
        } else if (x == 'l') {
            cur = '4';
        } else if (x == 'm' || x == 'n') {
            cur = '5';
        } else if (x == 'r') {
            cur = '6';
        }

        if (s_result.back() != cur) {
            s_result += cur;
        }

        if (s_result.size() == 4) {
            break;
        }
    }

    while (s_result.size() != 4) {
        s_result += '0';
    }

    std::cout << s_result;

    return 0;
}