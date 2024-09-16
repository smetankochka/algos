#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total = 45, n = 9;
    char c;
    while (n--) {
        cin >> c;
        total -= (c - '0');
    }

    cout << total;

    return 0;
}