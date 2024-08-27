#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 0 || n == 1) {
        cout << 1;
        return 0;
    }
    ll f1 = 2, f2 = 3, fsp;
    for (int i = 3; i <= n; i++) {
        fsp = f1;
        f1 = f2 % (1000000000 + 7);
        f2 = (fsp + f1) % (1000000000 + 7);
    }
    cout << f2;
    return 0;
}
