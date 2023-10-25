#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    deque<pair<ll, ll>> mas;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x, c;
            cin >> x >> c;
            mas.push_back(make_pair(x, c));
        } else {
            ll sums = 0;
            ll c;
            cin >> c;
            while (c > 0) {
                if (c < mas.front().second) {
                    sums += c * mas.front().first;
                    mas.front().second -= c;
                    c = 0;
                } else {
                    sums += mas.front().second * mas.front().first;
                    c -= mas.front().second;
                    mas.pop_front();
                }
            }
            cout << sums << "\n";
        }
    }
    return 0;
}
