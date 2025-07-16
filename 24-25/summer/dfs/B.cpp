#include <iostream>
#include <vector>


using namespace std;
using ll = long long;

const int MAXN=100;
vector<int> count(MAXN, 0);

int main() {
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        count[u-1]++;
        count[v-1]++;
    }
    for (int i = 0; i < n; i++) {
        cout << count[i] << " ";
    }
    return 0;
}