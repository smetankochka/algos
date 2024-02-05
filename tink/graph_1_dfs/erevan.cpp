#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> pervost(n + 1, 0);
    vector<int> vtorost(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        pervost[a]++;
        pervost[b]++;
    }
    for (int i = 1; i < n; ++i) {
        vtorost[i] = pervost[i];
        for (int elem : g[i]) {
            vtorost[i] += pervost[elem] - 1;
        }
    }
    int maxIndex = 1;
    for (int i = 2; i < vtorost.size(); i++) {
        if (vtorost[i] > vtorost[maxIndex]) {
            maxIndex = i;
        }
    }
    cout << maxIndex << endl;
    return 0;
}
