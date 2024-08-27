#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
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
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0 && mas[j-1] > mas[j]; j--) {
            swap(mas[j-1], mas[j]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}