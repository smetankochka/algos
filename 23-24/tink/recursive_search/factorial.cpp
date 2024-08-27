//
// Created by smetanka on 18.12.23.
//
#include <iostream>

using namespace std;
using ll = long long;

ll factorial(ll n) {
    if (n == 1 || n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin >> n;
    cout << factorial(n);
}