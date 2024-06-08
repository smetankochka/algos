//
// Created by mmura on 08.06.2024.
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned long long a, b, c;
    cin >> a >> b >> c;
    cout << a * b * c / (a * b + b * c + a * c);
    return 0;
}