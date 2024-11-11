#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, cur, nn;
    cin >> n;
    nn = n;
    unordered_map<int, int> hash_table;
    while (n--) {
        cin >> cur;
        if (!hash_table.count(cur)) {
            hash_table[cur] = 0;
        }
        hash_table[cur]++;
    }
    for (pair<int, int> p : hash_table) {
        if (p.second > nn / 2) {
            cout << p.first;
            return 0;
        }
    }
    cout << -1;
    return 0;
}