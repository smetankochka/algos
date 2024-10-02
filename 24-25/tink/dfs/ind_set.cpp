#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int n, m, s;
vector<int> graph[MAXN];
int dp[1 << 10];

bool isIndependentSet(int mask) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            for (int j : graph[i]) {
                if (mask & (1 << j)) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> s >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int maxIndependentSetSize = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (isIndependentSet(mask)) {
            int size = __builtin_popcount(mask);
            maxIndependentSetSize = max(maxIndependentSetSize, size);
        }
    }

    if (s <= maxIndependentSetSize) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}
