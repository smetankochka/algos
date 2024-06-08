// powered by smetanka on 09.06.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, cur, s = 0;
    cin >> n;

    vector<bool> mas(n + 1);
    for (ll i = 2; i < n; i++) {
        if (!mas[i]) {
            cur = i * i;
            while (cur <= n) {
                if(!mas[cur]) {
                    s += i;
                    mas[cur] = true;
                }
                cur += i;
            }
        }
    }

    cout << s;

    return 0;
}