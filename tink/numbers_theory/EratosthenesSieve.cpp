//
// Created by smetanka on 20.12.23.
//
#include <iostream>
#include <vector>

using namespace std;

void eratosthenesSieve(int A, int B) {
    vector<bool> prime(B + 1, true);
    for (int p = 2; p * p <= B; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= B; i += p) {
                prime[i] = false;
            }
        }
    }
    for (int number = max(2, A); number <= B; number++) {
        if (prime[number]) {
            cout << number << " ";
        }
    }
}

int main() {
    int A, B;
    cin >> A >> B;
    eratosthenesSieve(A, B);
    return 0;
}