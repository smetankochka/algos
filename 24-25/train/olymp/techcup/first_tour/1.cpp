#include <iostream>
#include <vector>
#include <algorithm>
using ll = long long;
using namespace std;

int countPrimesInRange(int t, int d) {
    vector<int> isPrime(1e7, 1);
    vector<int> vspom(2 * d + 1, 1);
    int count = 0;
    for (int p = 2; p < 1e7; p++) {
        if (isPrime[p]) {
            for (int multiple = p * p; multiple < 1e7; multiple += p) {
                isPrime[multiple] = 0;
            }
            for (int multiple = (t - d) + (p - ((t - d) % p)) % p; multiple <= t + d; multiple += p) {
                if (multiple < 1) continue;
                vspom[multiple - (t - d)] = 0;
            }
            if (p * p >= (t - d) && p * p <= (t + d)) {
                count++;
            }
        }
    }
    for (bool elem : vspom) {
        if (elem) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t, d;
    cin >> t >> d;
    int count = countPrimesInRange(t, d);
    cout << count;
    return 0;
}