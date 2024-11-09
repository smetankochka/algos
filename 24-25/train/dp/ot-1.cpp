#include <iostream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    int n, c1 = 0, c2 = 1, a, b;
    cin >> n;
    char c;
    string s;
    vector<bool> roditel(n, 0);
    vector<int> mas(n, 0);
    vector<bool> deti(n, 0);
    int count = 0;
    while (count != n - 1) {
        for (int i = 0; i < n; i++) {
            if (mas[i] < 3) {
                c1 = i;
                break;
            }
        }
        for (int i = c1 + 1; i < n;  i++) {
            if (mas[i] < 3 && !deti[i]) {
                c2 = i;
                break;
            }
        }
        cout << "+ " << c1 + 1 << " " << c2 + 1 << "\n";
        cout.flush();
        mas[c1]++;
        deti[c2] = 1;
        roditel[c1] = 1;
        mas[c2]++;
        count++;
        cin >> s;
        if (count == n - 1) {
            break;
        }
        cin >> c >> a >> b;
        mas[a - 1]++;
        mas[b - 1]++;
        roditel[a - 1] = 1;
        deti[b - 1] = 1;
        count++;
    }
    return 0;
}