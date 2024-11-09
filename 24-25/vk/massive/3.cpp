#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cur;
    int maximum = -1e9;
    while (n--) {
        cin >> cur;
        if (cur > maximum) {
            maximum = cur;
        }
    }
    cout << maximum;
    return 0;
}