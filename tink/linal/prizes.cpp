#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<ll> ps(n);
    vector<ll> mas(n);
    cin >> mas[0];
    ps[0] = mas[0];
    for (int i = 1; i < k; i++) {
        cin >> mas[i];
        ps[i] = mas[i] + ps[i - 1];
    }
    int l = 0, r = k - 1;
    ll maxs = ps[k - 1];
    for (int i = k; i < n; i++) {
        cin >> mas[i];
        ps[i] = mas[i] + ps[i - 1] - mas[i - k];
        if (maxs < ps[i]) {
            maxs = ps[i];
            l = i - k + 1;
            r = i;
        }
    }
    maxs = l > 0 ? ps[0] : 0;
    for (int i = 1; i < l; i++) {
        ps[i] = mas[i] + ps[i - 1];
        if (i >= k) {
            ps[i] -= mas[i - k];
        }
        if (maxs < ps[i]) {maxs = ps[i];}
    }
    for (int i = r + 1; i < n; i++) {
        if (i == r + 1) {
            ps[i] = mas[i];
        } else if (i <= r + k) {
            ps[i] = mas[i] + ps[i - 1];
        } else {
            ps[i] = mas[i] + ps[i - 1] - mas[i - k];
        }
        if (maxs < ps[i]) {maxs = ps[i];}
    }
    cout << maxs;
}