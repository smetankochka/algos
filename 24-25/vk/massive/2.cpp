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
    cin >> n;
    for (int elem : mas) {
        if (elem != n) {
            cout << elem << " ";
        }
    }
    return 0;
}