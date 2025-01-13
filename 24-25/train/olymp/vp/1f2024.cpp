#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int sop(int num) {
    if (num == 3) {
        return 2;
    }
    if (num == 4) {
        return 1;
    }
    return 0;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, count_all = 0, count_need = 0;
    char cur;
    cin >> n >> m;
    vector<vector<bool>> mas(n, vector<bool> (6, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cur;
            if (cur == 'X') {
                count_all++;
                mas[i][j] = true;
            }
        }
        for (int j = 3; j < 6; j++) {
            cin >> cur;
            if (cur == 'X') {
                count_all++;
                mas[i][j] = true;
            }
            if (mas[i][j] ^ mas[i][sop(j)]) {
                count_need++;
            }
        }
    }

    if (m < count_need || count_all + m > n * 6 || (count_all + m) % 2 != 0 || (m - count_need) % 2 != 0) {
        cout << "Impossible";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 3; j < 6; j++) {
            if (mas[i][j] ^ mas[i][sop(j)]) {
                mas[i][j] = true;
                mas[i][sop(j)] = true;
                m--;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 3; j < 6; j++) {
            if (m == 0) {
                break;
            }
            if (!mas[i][j]) {
                m -= 2;
                mas[i][j] = true;
                mas[i][sop(j)] = true;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            if (mas[i][j]) {
                cout << "X";
            } else {
                cout << ".";
            }
        }
        cout << "\n";
    }

    return 0;
}