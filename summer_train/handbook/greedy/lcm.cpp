// powered by smetanka on 24.07.2024

#include <iostream>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, tmp, a, b;
    cin >> n >> m;
    a = n;
    b = m;
    while (m != 0) {
        tmp = m;
        m = n % m;
        n = tmp;
    }

    cout << a * b / n;

    return 0;
}