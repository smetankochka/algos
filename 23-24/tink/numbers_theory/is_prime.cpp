//
// Created by smetanka on 18.12.23.
//
#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;
int main() {
    ll n;
    cin >> n;
    int gran = ceil(sqrt(n)) + 2 > n ? n : ceil(sqrt(n)) + 2;
    for (int i = 2; i < gran; i++) {
        if (n % i == 0) {
            cout << "composite";
            return 0;
        }
    }
    if (n == 1) {
        cout << "composite";
    } else {
        cout << "prime";
    }
}
