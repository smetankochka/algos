#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    x1--; x2--; y1--; y2--;
    char cur;
    vector<vector<bool>> lab(n, vector<bool>(n, true));
    vector<vector<int>> dist(n, vector<int>(n, 1e9));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cur;
            if (cur == '#') {
                lab[i][j] = false;
            }
        }
    }

    dist[y1][x1] = 0;
    queue<pair<int, int>> q;
    q.push({y1, x1});

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < n && lab[nx][ny] && dist[nx][ny] == 1e9) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    cout << dist[y2][x2] << endl;
    return 0;
}

