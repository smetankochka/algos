//
// Created by smetanka on 20.12.23.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findLargestSquare(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 0; j < m; j++) {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j] == 1) {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    int maxLen = 0;
    int topLeft_i = 0, topLeft_j = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] > maxLen) {
                maxLen = dp[i][j];
                topLeft_i = i - maxLen + 1;
                topLeft_j = j - maxLen + 1;
            }
        }
    }
    cout << maxLen << "\n";
    cout << topLeft_i + 1 << " " << topLeft_j + 1;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
    findLargestSquare(matrix);
    return 0;
}