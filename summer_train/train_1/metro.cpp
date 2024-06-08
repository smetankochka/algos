//
// Created by mmura on 08.06.2024.
//
#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, n, m, f, s;
    cin >> a >> b >> n >> m;

    if (b > a) {
        swap(a, b);
        swap(n, m);
    }

    f = min(n + (n + 1) * a, m + (m + 1) * b);
    s = max(n + (n - 1) * a, m + (m - 1) * b);

    if (f >= s) {
        cout << s << " " << f;
    } else {
        cout << -1;
    }

    return 0;
}