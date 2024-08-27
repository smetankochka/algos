//
// Created by smetanka on 18.12.23.
//
#include <iostream>
#include <vector>
#include <algorithm>

int countDivisors(int x, std::vector<int>& divisors) {
    int cnt = 0;
    for (int i = 1; i * 1LL * i <= x; i++) {
        if (x % i == 0) {
            cnt++;
            divisors.push_back(i);
            if (x / i != i) {
                cnt++;
                divisors.push_back(x / i);
            }
        }
    }
    return cnt;
}

int main() {
    int x;
    std::cin >> x;
    std::vector<int> divisors;
    int numDivisors = countDivisors(x, divisors);
    std::cout << numDivisors << "\n";
    sort(divisors.begin(), divisors.end());
    for (int i = 0; i < divisors.size(); i++) {
        std::cout << divisors[i] << " ";
    }
    return 0;
}
