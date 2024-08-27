#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    vector<ll> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    sort(mas.begin(), mas.end());
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    return 0;
}