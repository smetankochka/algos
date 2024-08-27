//
// Created by smetanka on 18.12.23.
//
#include <iostream>
long long count = 0;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    count++;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    std::cin >> n;
    int result = fibonacci(n);
    std::cout << count;
    return 0;
}