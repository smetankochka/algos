#include <vector>
#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2) {
        cout << 1;
        return 0;
    }
    ll f1 = 1, f2 = 1, fsp;
    for (int i = 3; i <= n; i++) {
        fsp = f1;
        f1 = f2;
        f2 = fsp + f1;
    }
    cout << f2;
    return 0;
}
