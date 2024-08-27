#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> picture(n);
    for (int i = 0; i < n; i++) {
        cin >> picture[i];
    }
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < k; p++) {
            for (int j = 0; j < m; j++) {
                for (int q = 0; q < k; q++) {
                    cout << picture[i][j];
                }
            }
            cout << "\n";
        }
    }
    return 0;
}
