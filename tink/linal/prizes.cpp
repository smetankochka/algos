#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + values[i - 1];
    }
    vector<int> pref(n + 1, 0);
    vector<int> suff(n + 1, 0);
    for (int i = 1; i <= n - k + 1; i++) {
        pref[i] = max(pref[i - 1], prefixSum[i + k - 1] - prefixSum[i - 1]);
    }
    for (int i = n - k; i >= 1; i--) {
        suff[i] = max(suff[i + 1], prefixSum[i + k] - prefixSum[i]);
    }
    int result = 1e9;
    for (int i = 1; i <= n - k + 1; i++) {
        result = min(result, max(pref[i - 1], suff[i + k]));
    }
    cout << result << endl;
    return 0;
}