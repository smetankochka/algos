#include <iostream>
#include <vector>

using namespace std;

vector<vector<short int>> g;
vector<vector<short int>> components;
vector<pair<bool, bool>> c;
int n, m;

void dfs(int i, int j, short int comp) {
    if (i < 0 || i >= n || j < 0 || j >= m || components[i][j] != -1 || g[i][j] < 2) {
        return;
    }
    components[i][j] = comp;
    if (g[i][j] == 2) {
        c[comp].first = true;
    }
    if (g[i][j] == 3) {
        c[comp].second = true;
    }
    dfs(i + 1, j, comp);
    dfs(i - 1, j, comp);
    dfs(i, j + 1, comp);
    dfs(i, j - 1, comp);
}

void labtoks() {
    cin >> n >> m;
    g.assign(n, vector<short int>(m));
    components.assign(n, vector<short int>(m, -1));
    char cur;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cur;
            if (cur == '#') {
                g[i][j] = 0;
            } else if (cur == '.') {
                g[i][j] = 1;
            } else if (cur == 'S') {
                g[i][j] = 2;
            } else {
                g[i][j] = 3;
            }
        }
    }
    short int comp = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (components[i][j] == -1 && g[i][j] >= 2) {
                c.push_back(make_pair(0, 0));
                comp++;
                dfs(i, j, comp);
            }
        }
    }

    for (int i = 0; i <= comp; i++) {
        if (c[i].first && c[i].second) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        labtoks();
    }
    return 0;
}

