//
// Created by smetanka on 20.12.23.
//
#include <iostream>
#include "cmath"

using namespace std;

int findLargestDivisor(int n) {
    int maxDivisor = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            maxDivisor = max(maxDivisor, i);
            maxDivisor = max(maxDivisor, n / i);
        }
    }
    return maxDivisor;
}

int main() {
    int N;
    cin >> N;
    if (N % 2 == 0) {
        cout << N / 2 << " " << N / 2;
        return 0;
    }
    int del = findLargestDivisor(N);
    cout << del << " " << N - del;
    return 0;
}

