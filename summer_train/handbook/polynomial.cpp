// powered by smetanka on 22.07.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, dif;

    cin >> n;
    n++;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cin >> m;
    m++;
    vector<int> s_mas(m);
    for (int i = 0; i < m; i++) {
        cin >> s_mas[i];
    }

    if (m > n) {
        swap(n, m);
        mas.swap(s_mas);
    }

    dif = n - m;
    for (int i = 0; i < m; i++) {
        mas[i + dif] += s_mas[i];
    }

    cout << --n << "\n";
    for (int elem : mas) {
        cout << elem << " ";
    }

    return 0;
}