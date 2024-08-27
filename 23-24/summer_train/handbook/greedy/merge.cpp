// powered by smetanka on 22.07.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


vector<int> merge(vector<int> &a, vector<int> &b) {
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j]) {
            ans[i + j] = a[i];
            i++;
        } else {
            ans[i + j] = b[j];
            j++;
        }
    }
    while (i < a.size()) {
        ans[i + j] = a[i];
        i++;
    }
    while (j < b.size()) {
        ans[i + j] = b[j];
        j++;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n;
    vector<int> f;
    vector<int> s;

    n--;
    cin >> m;
    f.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i];
    }

    while (n--) {
        cin >> m;
        s.resize(m);
        for (int i = 0; i < m; i++) {
            cin >> s[i];
        }
        f = merge(f, s);
    }

    for (int elem : f) {
        cout << elem << " ";
    }

    return 0;
}