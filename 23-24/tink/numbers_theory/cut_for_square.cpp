//
// Created by smetanka on 20.12.23.
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b, result = 0, tmp;
    cin >> a >> b;
    while (b != 0) {
        result += a / b;
        tmp = a;
        a = b;
        b = tmp % a;
    }
    cout << result;
}