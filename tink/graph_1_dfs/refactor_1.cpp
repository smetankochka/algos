#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n, m, v, u;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        cin >> v >> u;
        g[v - 1][u - 1] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << g[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}