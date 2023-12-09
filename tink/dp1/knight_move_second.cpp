//#include <iostream>
//#include <vector>
//
//int main() {
//    int n, m;
//    std::cin >> n >> m;
//    std::vector<std::vector<int>> dp(n, std::vector<int>(m, 0));
//    dp[0][0] = 1;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (i - 2 >= 0 && j - 1 >= 0) {
//                dp[i][j] += dp[i - 2][j - 1];
//            }
//            if (i - 2 >= 0 && j + 1 < m) {
//                dp[i][j] += dp[i - 2][j + 1];
//            }
//            if (i - 1 >= 0 && j - 2 >= 0) {
//                dp[i][j] += dp[i - 1][j - 2];
//            }
//            if (i + 1 < n && j - 2 >= 0) {
//                dp[i][j] += dp[i + 1][j - 2];
//            }
//        }
//    }
//    for (std::vector<int> dp1 : dp) {
//        for (int val : dp1) {
//            std::cout << val << " ";
//        }
//        std::cout << "\n";
//    }
//    std::cout << dp[n-1][m-1] << std::endl;
//    return 0;
//}
WRONG