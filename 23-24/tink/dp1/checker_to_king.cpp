#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> board(9, vector<int> (10, 0));
    int n, m, ans = 0;
    cin >> m >> n;
    board[n][m] = 1;
    for (int i = n + 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            board[i][j] += board[i - 1][j - 1] + board[i - 1][j + 1];
        }
    }
    for (int i = 1; i < 9; i++) {
        ans += board[8][i];
    }
    cout << ans;
}