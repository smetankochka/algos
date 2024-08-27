#include "iostream"
#include "algorithm"
#include "vector"
#include "deque"
#include <string>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    string ans, gr, tmpf;
    int maxz = -1e9, tmpz;
    for (int i = 0; i < n; i++) {
        cin >> tmpz >> tmpf >> gr;
        if (gr == "Russia"  && tmpz > maxz) {
            ans = tmpf;
            maxz = tmpz;
        }
    }
    cout << ans;
    return 0;
}
