//
// Created by smetanka on 04.05.24.
//
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int left = 1;
    int right = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        cout << mid << endl;
        fflush(stdout);

        int res;
        cin >> res;

        if (res == 0) {
            return 0;
        } else if (res == -1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}
