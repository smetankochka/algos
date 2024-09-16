#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using ll = long long;
using ull = __uint128_t;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll m;
    //ull mod = 18446744073709551616;
    int n, dif = -1;
    cin >> m >> n;
    vector<ll> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    sort(mas.begin(), mas.end());

    vector<ll> pref(n + 1);
    pref[-1] = 0;
    for (int i = 0; i < n; i++) {
        pref[i] = pref[i - 1] + mas[i];
    }
    ll prefall = pref[n - 1];

    ll r = mas[n - 1] - 1, l = 0, mid, curm;
    while (l < r) {
        mid = (l + r) / 2;
        int indx = distance(mas.begin(), upper_bound(mas.begin(), mas.end(), mid));
        curm = prefall - pref[indx - 1] - (n - indx) * mid;
        if (curm > m) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << l << " " << r << "\n";
    



    return 0;
}