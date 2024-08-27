#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int result = 0;
    int num = 0;
    int sign = 1;
    for (char c : s) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        } else if (c == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        }
    }
    result += sign * num;
    cout << result;
    return 0;
}
