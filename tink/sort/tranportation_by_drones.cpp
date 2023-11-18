#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    int l = n * m;
    vector<int> mas(l);
    for (int i = 0; i < l; ++i) {
        cin >> mas[i];
    }
    int k;
    cin >> k;
    vector<int> plane(k);
    for (int i = 0; i < k; ++i) {
        cin >> plane[i];
    }
    sort(mas.begin(), mas.end());
    sort(plane.begin(), plane.end());
    int count = 0, f = 0, s = 0;
    while (f < l && s < k) {
        if (mas[f] >= plane[s]) {
            s++;
            count++;
        }
        f++;
    }
    cout << count;
    return 0;
}