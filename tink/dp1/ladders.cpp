#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll countStaircases(int n, vector<vector<ll>>& memo) {
    if (n <= 1) {
        return 1;
    }
    if (memo[n][n] != -1) {
        return memo[n][n];
    }
    ll ways = 0;
    for (int i = 1; i <= n; i++) {
        ways += countStaircases(n - i, memo);
    }
    memo[n][n] = ways;
    return ways;
}
int main() {
    int n;
    cin >> n;
    vector<vector<ll>> memo(n + 1, vector<ll>(n + 1, -1));
    ll result = countStaircases(n, memo);
    cout << result;
    return 0;
}