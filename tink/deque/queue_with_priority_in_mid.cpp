#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
int main() {
    int q;
    cin >> q;
    deque<int> first_queue;
    deque<int> second_queue;
    while (q--) {
        char type;
        cin >> type;
        if (type == '+') {
            int i;
            cin >> i;
            second_queue.push_back(i);
        } else if (type == '-') {
            cout << first_queue.front() << "\n";
            first_queue.pop_front();
        } else {
            int i;
            cin >> i;
            second_queue.push_front(i);
        }
        while (second_queue.size() > first_queue.size()) {
            first_queue.push_back(second_queue.front());
            second_queue.pop_front();
        }
    }
   
