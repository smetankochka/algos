#include <iostream>
#include <vector>

using namespace std;

void primeFactors(int n) {
    while (n % 2 == 0) {
        cout << 2 << endl;
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            cout << i << endl;
            n = n / i;
        }
    }
    if (n > 2) {
        cout << n << endl;
    }
}

int main() {
    int N;
    cin >> N;
    primeFactors(N);
    return 0;
}
