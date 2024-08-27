#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    long long tmp = 0;
    vector<int> candies(n + 1, 0);
    vector<long long> prefix_sum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> candies[i];
        prefix_sum[i] = prefix_sum[i - 1] + candies[i];
    }
    for (int i = 0; i < m; ++i) {
        int query_type;
        cin >> query_type;
        if (query_type == 1) {
            int x;
            cin >> x;
            candies[x]++;
            for (int j = x; j <= 100; ++j) {
                prefix_sum[j]++;
            }
            tmp++;
        } else {
            int l, r;
            cin >> l >> r;
            if (r <= 100) {
                cout << prefix_sum[r] - prefix_sum[l - 1] << "\n";
            } else {
                cout << prefix_sum[r] - prefix_sum[l - 1] + tmp << "\n";
            }
        }
    }
    return 0;
}
