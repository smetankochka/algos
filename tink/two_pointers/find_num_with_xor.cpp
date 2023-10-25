#include <iostream>
using namespace std;
int main() {
    int n, ans;
    cin >> n;
    cin >> ans;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans;
}
