#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, ans = 0, power = 0;
    cin >> m;
    n = m;

    while (n > 1) {
        n /= (ll)2;
        power++;
    }
    ans += power + 1;
    if (power > 1) {
        ans += (power * (power - 1)) / 2;
    }
    ll cur = 1, prev, vse;
    ll count = 0;
    for (int i = 0; i < power; i++) {
        cur += cur;
    }
    prev = cur / (ll)2;
    vse = cur + prev;
    while (vse <= m && prev > 0) {
        prev /= (ll) 2;
        vse += prev;
        count++;
    }
    cout << ans + count;

    return 0;
}