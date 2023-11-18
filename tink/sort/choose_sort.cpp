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
    for (int i = 0; i < n - 1; i++) {
        int minim = mas[i];
        int index = i;
        bool flag = false;
        for (int j = i + 1; j < n; j++) {
            if (minim > mas[j]) {
                minim = mas[j];
                index = j;
                flag = true;
            }
        }
        if (flag) {
            swap(mas[index], mas[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
}