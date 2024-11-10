#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, target;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    cin >> target;
    int l = 0, r = n, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (mas[mid] > target) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (mas[l] == target) {
        cout << l;
    } else {
        cout << r;
    }
    return 0;
}