#include <iostream>
#include <vector>

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

    int curd = mas[0];
    for (int i = 1; i < n; i++) {
        if (mas[i] > curd) {
            curd = mas[i];
        } else if (mas[i] < curd) {
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        if (mas[i] != curd) {
            cout << mas[i] << " ";
        }
    }

    return 0;
}