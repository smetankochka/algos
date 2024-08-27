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

vector<int> merge_sort(vector<int> mas) {
    int l = mas.size();
    if (l <= 1) {
        return mas;
    }
    vector<int> f(l / 2);
    vector<int> s(l / 2 + l % 2);
    for (int i = 0; i < l / 2; i++) {
        f[i] = mas[i];
    }
    for (int i = l / 2; i < l; i++) {
        s[i - l / 2] = mas[i];
    }
    f = merge_sort(f);
    s = merge_sort(s);
    return merge(f, s);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    mas = merge_sort(mas);

    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }

    return 0;
}