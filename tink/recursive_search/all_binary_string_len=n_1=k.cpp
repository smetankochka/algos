#include <iostream>
#include <vector>
using namespace std;
void permutation(vector<bool> &perm, int n, int k) {
    if (n == 0 || n - k < 0) {
        if (k != 0) {return;}
        for (int i = 0; i < perm.size(); i++) {
            if (perm[i]) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
        return;
    }
    n--;
    perm.push_back(false);
    permutation(perm, n, k);
    if (k == 0) {
        perm.pop_back();
        return;
    }
    perm.back() = true;
    permutation(perm, n, k - 1);
    perm.pop_back();
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> perm;
    permutation(perm, n, k);
    return 0;
}