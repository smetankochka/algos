#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k, last, now, minim = 10e8;
    cin >> n >> k;
    vector<int> mas(n, 0);
    cin >> last;
    for (int i = 1; i < n; i++) {
        cin >> now;
        mas[i] = last < now ? mas[i - 1] + 1 : mas[i - 1];
        last = now;
    }
    for (int i = k - 1; i < n; i++) {
        if (minim > mas[i] - mas[i - k + 1]) {
            minim = mas[i] - mas[i - k + 1];
        }
    }
    cout << minim;
}
