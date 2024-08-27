#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    ll sum = 0, cur, maxsum = -1e18;
    int ansl = 1, ansr = 1, left_position = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cur;
        sum += cur;
        if (sum > maxsum) {
            maxsum = sum;
            ansl = left_position + 1;
            ansr = i;
        }
        if (sum <= 0) {
            sum = 0;
            left_position = i;
        }
    }
    cout << ansl << " " << ansr << " " << maxsum;
    return 0;
}