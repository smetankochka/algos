#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

vector<vector<pair<int, int>>> ans;
vector<vector<bool>> visited;

void findPaths(int h, int w, const vector<vector<bool>>& grid, int x, int y, vector<pair<int, int>>& currentPath) {
    if (y == w - 1) {
        currentPath.push_back({x + 1, y + 1});
        ans.push_back(currentPath);
    }
    visited[x][y] = true;
    currentPath.push_back({x + 1, y + 1});

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] && !visited[nx][ny]) {
            findPaths(h, w, grid, nx, ny, currentPath);
            currentPath.pop_back();
        }
    }

    visited[x][y] = false;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<bool>> grid(h, vector<bool>(w, false));
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            char c;
            cin >> c;
            if (c == '#') {
                grid[i][j] = true;
            }
        }
    }

    visited.assign(h, vector<bool>(w, false));

    for (int i = 0; i < h; ++i) {
        if (grid[i][0]) {
            vector<pair<int, int>> currentPath;
            findPaths(h, w, grid, i, 0, currentPath);
        }
    }
    if (ans.size() == 0) {
        cout << "NO";
        return 0;
    }
    if (ans.size() == 1) {
        cout << "YES\n";
    } else {
        cout << "MULTIPLE\n";
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].size() << "  ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j].first <<  " " << ans[i][j].second << "  ";
        }
        cout << "\n";
        if (i == 1) {
            break;
        }
    }
    return 0;
}

