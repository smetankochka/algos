#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ll n, m, tmp = 0;
    cin >> n >> m;
    vector<ll> snowballs(n);
    for (int i = 0; i < n; ++i) {
        cin >> snowballs[i];
    }
    vector<ll> prefixSum(n);
    prefixSum[0] = snowballs[0];
    for (int i = 1; i < n; ++i) {
        prefixSum[i] += prefixSum[i - 1] + snowballs[i];
    }
    for (int i = 0; i < m; ++i) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            for (int j = x - 1; j < 100; ++j) {
                prefixSum[j]++;
            }
            tmp++;
        } else {
            int li, ri;
            cin >> li >> ri;
            if (li == 1) {
                if (ri <= 100) {
                    cout << prefixSum[ri - 1] << "\n";
                } else {
                    cout << prefixSum[ri - 1] + tmp << "\n";
                }
            } else {
                if (ri <= 100) {
                    cout << prefixSum[ri - 1] - prefixSum[li - 2] << "\n";
                } else {
                    if (li <= 100) {
                        cout << prefixSum[ri - 1] - prefixSum[li - 2] + tmp << "\n";
                    } else {
                        cout << prefixSum[ri - 1] - prefixSum[li - 2] << "\n";
                    }
                }
            }
        }
    }
    return 0;
}