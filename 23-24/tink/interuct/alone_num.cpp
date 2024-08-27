//
// Created by smetanka on 04.05.24.
//
#include <iostream>
#include "vector"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> mas(n, -1);

    int left = 1;
    int right = n;

    while (right - left > 1) {
        int mid = (left + right) / 2;
        mid += mid % 2;

        if (mas[mid - 1] == -1) {
            cout << "? " << mid << endl;
            fflush(stdout);

            cin >> mas[mid - 1];
        }
        int res = mas[mid - 1];

        if (mas[mid - 2] == -1) {
            cout << "? " << mid - 1 << endl;
            fflush(stdout);

            cin >> mas[mid - 2];
        }
        int res1 = mas[mid - 2];

        if (res1 == res) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (mas[left - 1] == -1) {
        cout << "? " << left << endl;
        fflush(stdout);
        cin >> mas[left - 1];
    }
    cout << "! " << mas[left - 1];
    return 0;
}
