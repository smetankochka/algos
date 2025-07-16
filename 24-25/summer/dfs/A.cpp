#include <iostream>
#include <vector>


using namespace std;
using ll = long long;

const int MAXN=100;
vector<vector<bool>> g(MAXN, vector<bool> (MAXN, false));

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int v, u;
        cin >> u >> v;
        g[u-1][v-1] = true;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (g[i][j]) {
                cout << 1 << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}