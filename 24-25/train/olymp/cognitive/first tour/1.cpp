#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        if (n > m) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n - 1; i++) {
            cout << 1 << " ";
        }
        cout << m - n + 1 << "\n";
    }
    
    return 0;
}