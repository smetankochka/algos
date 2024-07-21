// powered by smetanka on 22.07.2024

#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, minimal, index_min;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    for (int i = 0; i < n - 1; i++) {
        minimal = 1e9;
        for (int j = i; j < n; j++) {
            if (mas[j] < minimal) {
                minimal = mas[j];
                index_min = j;
            }
        }
        swap(mas[i], mas[index_min]);
    }

    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }

    return 0;
}