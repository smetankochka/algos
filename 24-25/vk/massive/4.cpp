#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, last, cur, minimum = 1e9, ans1, ans2;
    cin >> n >> last;
    n--;
    while (n--) {
        cin >> cur;
        if (abs(last - cur) < minimum) {
            ans1 = last;
            ans2 = cur;
            minimum = abs(last - cur);
        }
        last = cur;
    }
    cout << ans1 << " " << ans2;
    return 0;
}