#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, f;
    ll count = 0;
    cin >> n >> f;
    vector<int> statement(n);
    for (int i = 0; i < n; i++) {cin >> statement[i];}
    int l = 0, r = 1;
    while (l < n - 1 && r < n) {
        if (statement[r] - statement[l] > f) {
            count += (ll)(n - r);
            l++;
        } else {
            r++;
        }
    }
    cout << count;
    return 0;
}
