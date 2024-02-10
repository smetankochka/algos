#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <set>
#include <climits>
const int INF = INT_MAX;
using namespace std;

int main() {
    int n, s, t, v, w;
    cin >> n;
    vector<pair<int, int>> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i].first >> input[i].second;
    }
    cin >> s >> t;
    s--;
    t--;
    vector<int> dist(n, 1e9);
    vector<bool> is_visited(n, false);
    dist[s] = 0;
    for (int iter_n = 0; iter_n < n; ++iter_n) {
        // ============== Выбираем ближайшую непосещённую ==============
        int closest_not_visited = -1;
        int closest_dist = INF;
        for (int v = 0; v < n; ++v) {
            if (!is_visited[v] && dist[v] < closest_dist) {
                closest_dist = dist[v];
                closest_not_visited = v;
            }  
        }
        
        is_visited[closest_not_visited] = true;

        // ============== Релаксируем рёбра, идущие из неё ==============

        for (int to = 0; to < n; ++to) {
            if (to == closest_not_visited) {
                continue;
            }
            w = pow(input[to].first - input[closest_not_visited].first, 2) + pow(input[to].second - input[closest_not_visited].second, 2);
            dist[to] = min(dist[to], dist[closest_not_visited] + w);
        }
    }
    cout << dist[t];
    return 0;
}