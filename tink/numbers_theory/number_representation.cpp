//
// Created by smetanka on 20.12.23.
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin >> N;
    if (N % 2 == 0) {
        cout << N / 2 << " " << N / 2;
    } else {
        cout << N - 1 << " " << 1;
    }
    return 0;
}
