#include <iostream>
#include <vector>
using namespace std;
void permutation(vector<int> &perm, int n, int k) {
    if ((int)perm.size() == k) {
        for (int i = 0; i < (int)perm.size(); i++) {
            cout << perm[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (perm.empty()) {
        perm.push_back(1);
        permutation(perm, n, k);
        for (int i = 2; i <= n; i++) {
            perm.back() = i;
            permutation(perm, n, k);
        }
        perm.pop_back();
    } else if (k - (int)perm.size() < perm.back()) {
        bool f = true;
        for (int i = 1; i <= n; i++) {
            bool flag = true;
            for (int j = 0; j < (int)perm.size(); j++) {
                if (perm[j] == i) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                if (f && perm.back() > i) {
                    perm.push_back(i);
                    f = false;
                    permutation(perm, n, k);
                } else if (!f && perm[perm.size() - 2] > i) {
                    perm.back() = i;
                    permutation(perm, n, k);
                }
            }
        }
        perm.pop_back();
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> perm;
    permutation(perm, n, k);
    return 0;
}