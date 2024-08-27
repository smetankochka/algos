#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void permutation(vector<bool> &perm, int n) {
    if (n == 0) {
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
    permutation(perm, n);
    perm.back() = true;
    permutation(perm, n);
    perm.pop_back();
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<bool> perm;
    permutation(perm, n);
    return 0;
}