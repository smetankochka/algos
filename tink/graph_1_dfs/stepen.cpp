#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m, v, u;
    cin >> n >> m;
    vector<int> g(n, 0);
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        g[v - 1]++;
        g[u - 1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << g[i] << " ";
    }
    return 0;
}