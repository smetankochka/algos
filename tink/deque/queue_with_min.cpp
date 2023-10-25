#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    deque<ll> min_of_queue;
    deque<ll> queuemain;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            ll x;
            cin >> x;
            queuemain.push_back(x);
            while (!min_of_queue.empty() && min_of_queue.back() >= x) {
                min_of_queue.pop_back();
            }
            min_of_queue.push_back(x);
        } else if (type == 2) {
            cout << queuemain.front() << "\n";
            if (!min_of_queue.empty() && queuemain.front() == min_of_queue.front()) {
                min_of_queue.pop_front();
            }
            queuemain.pop_front();
        } else if (type == 3) {
            int i;
            cin >> i;
            cout << queuemain[i - 1] << "\n";
        } else {
            cout << min_of_queue.front()<< "\n";
        }
    }
    return 0;
}
