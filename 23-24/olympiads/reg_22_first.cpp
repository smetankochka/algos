#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, type, move = 0, m, ind, pointer;
    ll s = 0, x;
    cin >> n;
    vector<ll> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
        s += mas[i];
    }
    cin >> q;
    while (q--) {
        cin >> type;
        if (type == 1) {
            cin >> ind >> x;
            ind--;
            if (move > ind) {
                pointer = move - ind;
                pointer = n - pointer;
            } else {
                pointer = ind - move;
            }
            s -= mas[pointer];
            mas[pointer] = x;
            s += x;
            cout << s << "\n";
        } else {
            cin >> m;
            move += m;
            move %= n;
            cout << s << "\n";
        }
    }
    return 0;
}