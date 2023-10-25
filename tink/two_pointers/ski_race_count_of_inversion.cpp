#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
ll mergesort(vector<ll> &mas, int left, int right) {
    if (left == right) {
        return 0;
    }
    if (left == right - 1) {
        if (mas[left] > mas[right]) {
            swap(mas[left], mas[right]);
            return 1;
        }
        return 0;
    }
    int mid = left + (right - left) / 2;
    ll c = mergesort(mas, left, mid) + mergesort(mas, mid + 1, right);
    int l = left, r = mid + 1, i = 0, n = right - left + 1;
    ll count = mid + 1 - left;
    vector<ll> tmp(n);
    while (l <= mid || r <= right) {
        if (l > mid) {
            tmp[i] = mas[r];
            r++;
            c += count;
        } else if (r > right) {
            tmp[i] = mas[l];
            l++;
        } else if (mas[l] <= mas[r]) {
            tmp[i] = mas[l];
            l++;
            count--;
        } else {
            tmp[i] = mas[r];
            r++;
            c += count;
        }
        i++;
    }
    for (int i = 0; i < n; i++) {
        mas[left + i] = tmp[i];
    }
    return c;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, l;
    cin >> n >> l;
    vector<ll> mas(n);
    for (int i = 0; i < n; ++i) {
        ll w;
        cin >> w;
        mas[i] = l * w + i;
    }
    int left = 0, right = n - 1;
    cout << mergesort(mas, left, right);
}
