#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

bool comp(pair<ll, int> a, pair<ll, int> b) {
    return b < a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k, p;
    cin >> n >> k >> p;
    ll vsego_tov = 0, pod_skidku = 0;
    vector<pair<ll, ll>> mas(n);
    vector<pair<ll, int>> skid;
    for (int i = 0; i < n; i++) {
        cin >> mas[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> mas[i].second;
        vsego_tov += mas[i].second;
        if (mas[i].first <= p) {
            pod_skidku += mas[i].second;
            skid.push_back(make_pair(mas[i].first, i));
        }
    }
    sort(skid.begin(), skid.end(), comp);
    ll l = 0, r = vsego_tov / k + 1, mid;
    if (r > pod_skidku) {
        r = pod_skidku + 1;
    }
    while (r - l > 1) {
        mid = (l + r) / 2;
        if ((vsego_tov - mid) / k >= mid) {
            l = mid;
        } else {
            r = mid;
        }
    }
    
    for (pair<ll, int> p : skid) {
        if (l > 0) {
            if (mas[p.second].second <= l) {
                l -= mas[p.second].second;
                mas[p.second].second = 0;
            } else {
                mas[p.second].second -= l;
                l = 0;
            }
        } else {
            break;
        }
    }
    ll ans = 0;
    for (pair<ll, ll> p : mas) {
        ans += p.first * p.second;
    }
    cout << ans;
    return 0;
}