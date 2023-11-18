#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void mergesort(vector<int> &mas, int left, int right) {
    if (left == right) {
        return;
    }
    if (left == right - 1) {
        if (mas[left] > mas[right]) {
            swap(mas[left], mas[right]);
        }
        return;
    }
    int mid = left + (right - left) / 2;
    mergesort(mas, left, mid);
    mergesort(mas, mid + 1, right);
    int l = left, r = mid + 1, i = 0, n = right - left + 1;
    vector<int> tmp(n);
    while (l <= mid || r <= right) {
        if (l > mid) {
            tmp[i] = mas[r];
            r++;
        } else if (r > right) {
            tmp[i] = mas[l];
            l++;
        } else if (mas[l] < mas[r]) {
            tmp[i] = mas[l];
            l++;
        } else {
            tmp[i] = mas[r];
            r++;
        }
        i++;
    }
    for (int i = 0; i < n; i++) {
        mas[left + i] = tmp[i];
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    mergesort(mas, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    return 0;
}