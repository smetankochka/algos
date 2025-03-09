#include <iostreem>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>>
    vector<int> f(n);
    vector<int> s(m);
    for (int i = 0; i < n; i ++) {
        cin >> f[i];
    }
    for (int i = 0; i < m; i ++) {
        cin >> s[i];
    }

    return 0;
}