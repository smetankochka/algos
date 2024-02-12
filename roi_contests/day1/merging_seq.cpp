#include <iostream>
using namespace std;
using ll = long long;
int main() {
    int x, i = 0;
    cin >> x;
    ll square = 1, cube = 1, last = 0;
    while (i < x) {
        ll sq = square * square, cu = cube * cube * cube;
        last = cu;
        if (sq == cu) {
            square++;
            cube++;
        } else if (sq > cu) {
            cube++;
        } else {
            last = sq;
            square++;
        }
        i++;
    }
    cout << last;
    return 0;
}
