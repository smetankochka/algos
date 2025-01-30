#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    if (n % 2 == 1 || k > n) {
        cout << -1;
        return 0;
    }
    if (k % 2 == 1) {
        if (k == 1) {
            cout << -1;
            return 0;
        }
        if (k == 3) {
            cout << 1 << " " << n / 2 << " " << (n - 1) / 2;
            return 0;
        }
        if (k == 5) {
            cout << 1 << " " << 2 << " " << 3 << " " << (n - 6) / 2 << " " << (n - 6) / 2;
            return 0;
        }
        int zap = ((n - 6) - (k - 5)) / 2;
        cout << 1 << " " << 2 << " " << 3 << " " << zap << " " << zap << " ";
        for (int i = 0; i < k - 5; i++) {
            cout << 1 << " ";
        }  





        return 0;
    }
    if (k == 2) {
        cout << n / 2 << " " << n / 2;
        return 0;
    }
    int zap = (n - (k - 2)) / 2;
    cout << zap << " " << zap << " ";
    for (int i = 0; i < k - 2; i++) {
        cout << 1 << " ";
    }
    
    return 0;
}