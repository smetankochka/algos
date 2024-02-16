#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> components(n);
    for (int i = 0; i < n; ++i) {
        cin >> components[i];
    }

    int devices = 1;
    while (true) {
        int current_device = 0;
        int current_time = 0;
        bool valid = true;

        for (int i = 0; i < n; ++i) {
            if (current_time >= components[i]) {
                current_time = components[i];
            } else {
                current_time = components[i] + 1;
                current_device++;
            }

            if (current_device == devices) {
                valid = false;
                break;
            }
        }

        if (valid) {
            break;
        } else {
            devices++;
        }
    }

    cout << devices << endl;

    return 0;
}
