#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> mas(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        mas[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int ai, bi;
        cin >> ai >> bi;
        ai--;
        bi--;
        if (abs(mas[ai] - ai) > k) {
            count--;
        }
        if (abs(mas[bi] - bi) > k) {
            count--;
        }
        swap(mas[ai], mas[bi]);
        if (abs(mas[bi] - bi) > k) {
            count++;
        }
        if (abs(mas[ai] - ai) > k) {
            count++;
        }
        if (count > 0) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    return 0;
}

