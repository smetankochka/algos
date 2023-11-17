#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
void permutation(vector<int> &perm, int n, int k) {
    if (n == 0) {
        for (int i = 0; i < perm.size(); i++) {
            cout << perm[i];
        }
        cout << "\n";
        return;
    }
    n--;
    perm.push_back(0);
    permutation(perm, n, k);
    for (int i = 1; i < k; i++) {
        perm.back() = i;
        permutation(perm, n, k);
    }
    perm.pop_back();
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