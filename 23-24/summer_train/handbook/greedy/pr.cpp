// powered by smetanka on 25.07.2024

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, res = 0;
    cin >> n;
    vector<ll> prices(n);
    vector<ll> clicks(n);
    for (int i = 0; i < n; i++) {cin >> prices[i];}
    for (int i = 0; i < n; i++) {cin >> clicks[i];}
    sort(prices.begin(), prices.end());
    sort(clicks.begin(), clicks.end());
    for (int i = 0; i < n; i++) {res += clicks[i] * prices[i];}
    cout << res;

    return 0;
}