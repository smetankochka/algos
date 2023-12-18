//
// Created by smetanka on 18.12.23.
//
#include <iostream>

int countDivisors(int x) {
    int divisors = 1;
    for (int i = 2; i * i <= x; i++) {
        int cnt = 0;
        while (x % i == 0) {
            x /= i;
            cnt++;
        }
        divisors *= (cnt + 1);
    }
    if (x > 1) {
        divisors *= 2;
    }
    return divisors;
}

int main() {
    int x;
    std::cin >> x;
    std::cout << countDivisors(x);
    return 0;
}
