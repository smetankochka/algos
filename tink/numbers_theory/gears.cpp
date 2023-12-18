//
// Created by smetanka on 18.12.23.
//
#include <iostream>

using namespace std;

int euclidean(int n, int m) {
    while (m != 0) {
        int t = m;
        m = n % m;
        n = t;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    cout << n / euclidean(n, k) * k;
    return 0;
}