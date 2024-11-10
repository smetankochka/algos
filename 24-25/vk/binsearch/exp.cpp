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
    int l = 0, r = 1;
    while (mas[r] <= target) {
        l = r;
        r *= 2;
    }
    cout << l << " " << r;
    return 0;
}