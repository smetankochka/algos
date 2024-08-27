#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int b, n;
    cin >> b >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    sort(mas.begin(), mas.end());
    int last = -1, count = 0, i = 0;
    while (i < n) {
        if (last == -1) {
            if (mas[i] >= b) {
                last = mas[i];
                count++;
            }
        } else if (mas[i] - last >= 3) {
            count++;
            last = mas[i];
        }
        i++;
    }
    cout << count;
    return 0;
}