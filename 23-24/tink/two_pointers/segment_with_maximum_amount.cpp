#include <iostream>
using namespace std;
using ll = long long;
int main() {
    ll maxsum = -1e18, sum = 0;
    int ansleft = 1, ansright = 1, left_position = 0, n;
    cin >> n;
    for (int r = 1; r <= n; r++) {
        ll cur;
        cin >> cur;
        sum += cur;
        if (sum > maxsum) {
            maxsum = sum;
            ansleft = left_position + 1;
            ansright = r;
        }
        if (sum <= 0) {
            sum = 0;
            left_position = r;
        }
    }
    cout << ansleft << "\n" << ansright;
    return 0;
}
