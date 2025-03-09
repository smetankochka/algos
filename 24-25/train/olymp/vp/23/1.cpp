#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, a, b, c;
    cin >> t >> a >> b >> c;
    if ((a + b + c) % 3 != 0) {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    int target = (a + b + c) / 3;
    int count = 0;
    if (a != target) {
        count += abs(target - a);
    }
    if (b != target) {
        count += abs(target - b);
    }
    if (c != target) {
        count += abs(target - c);
    }
    cout << count / 2 << "\n";
    if (t == 0) {
        return 0;
    }
    while (a != target || b != target || c != target) {
        if (b < target && b < a) {
            swap(a, b);
        }
        if (c < target && c < a) {
            swap(a, c);
        }
        if (b > target && b > c) {
            swap(b, c);
        }
        int granica = min(abs(target - a), abs(target - c));
        for (int i = 0; i < granica; i++) {
            cout << a++ << " " << c-- << "\n";
        }
    }
    return 0;
}