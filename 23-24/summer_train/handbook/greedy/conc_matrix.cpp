// powered by smetanka on 22.07.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, cur;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int> (m, 0));

    for (int q = 0; q < 2; q++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> cur;
                matrix[i][j] += cur;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}