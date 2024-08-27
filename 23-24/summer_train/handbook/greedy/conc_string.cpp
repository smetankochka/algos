// powered by smetanka on 22.07.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<char> mas(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> mas[i];
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << mas[i + n];
    }

    return 0;
}