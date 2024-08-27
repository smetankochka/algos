#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, d;
    cin >> n >> m >> d;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }
    int l, maximum = -1, have_deleted;
    for (int grade = 1; grade <= m; grade++) {
        l = 0;
        have_deleted = 0;
        for (int r = 0; r < n; r++) {
            if (mas[r] != grade) {
                have_deleted++;
            }
            while (have_deleted > d) {
                if (mas[l] != grade) {
                    have_deleted--;
                }
                l++;
            }
            if (maximum < r - l + 1 - have_deleted) {
                maximum = r - l + 1 - have_deleted;
            }
        }
    }

    cout << maximum << "\n";

    return 0;
}