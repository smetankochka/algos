//
// Created by smetanka on 18.12.23.
//
//
// Created by smetanka on 18.12.23.
//
#include <iostream>

using namespace std;

int euclidean(int n, int m) {
    while (m != 0) {
        int t = m;
        m = n % m;
        n = t;
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, ans, tmp;
    cin >> n >> ans;
    n--;
    while (n--) {
        cin >> tmp;
        ans = euclidean(ans, tmp);
    }
    cout << ans;
    return 0;
}