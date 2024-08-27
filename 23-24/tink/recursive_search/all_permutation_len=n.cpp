#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void permutation(vector<int> &perm, int n) {
    if (perm.size() == n) {
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
        }
        cout << "\n";
        return;
    }
    bool f = true;
    for (int i = 1; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < perm.size(); j++) {
            if (perm[j] == i) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (f) {
                perm.push_back(i);
                f = false;
            } else {
                perm.back() = i;
            }
            permutation(perm, n);
        }
    }
    perm.pop_back();
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> perm;
    permutation(perm, n);
    return 0;
}