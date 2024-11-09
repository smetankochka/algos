#include <iostream>
#include <cmath>
using namespace std;
using  ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    ll d1 = 0, d2 = 0;
    for (int i = 2; i <= n; i++){
        d1 = d2;
        d2 = d1 + i - 1;
    }
    ll m = d2 * 3 + n * 3;
    int count = 1;
    if (m % 2 == 1) {
        count++;
    }
    for (int dl = 4; dl < 1e6; dl++) {
        if (dl * (dl + 1) / 2 > m) {
            break;
        }
        if (dl % 2 == 0) {
            if (m % dl == dl / 2) {
                count++;
            }
        } else {
            if (m % dl == 0) {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}