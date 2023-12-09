//
// Created by smetanka on 09.12.23.
//
#include <iostream>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main() {
    int n, a1, k, b, m;
    cin >> n >> a1 >> k >> b >> m;
    vector<int> a(n);
    a[0] = a1;
    for (int i = 1; i < n; ++i) {
        a[i] = (k * a[i - 1] + b) % m;
    }
    vector<int> dp(n + 1, INF);
    dp[0] = -INF;
    for (auto x : a) {
        *lower_bound(dp.begin(), dp.end(), x) = x;
    }
    for (int i = n; i >= 1; --i) {
        if (dp[i] != INF) {
            cout << i;
            return 0;
        }
    }
    return 0;
}
