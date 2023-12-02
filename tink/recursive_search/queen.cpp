#include <iostream>
using namespace std;
int board[10];
bool check(int i, int j, int k) {
    if (k == i) return true;
    return board[k] != j && (i - k) != (j - board[k]) && (i - k) != (board[k] - j) && check(i, j, k + 1);
}
int put_queen(int n, int i, int j) {
    if (i == n) return 1;
    if (j < n) {
        int r = 0;
        if (check(i, j, 0)) {
            board[i] = j;
            r = put_queen(n, i + 1, 0);
        }
        return r + put_queen(n, i, j + 1);
    }
    return 0;
}
int main() {
    int n;
    cin >> n;
    cout << put_queen(n, 0, 0);
    return 0;
}