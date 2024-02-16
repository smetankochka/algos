#include <iostream>
#include <cmath>
using namespace std;

pair<int, int> coord(char c) {
    int x, y;
    switch (c) {
        case '1': x = 0; y = 0; break;
        case '2': x = 1; y = 0; break;
        case '3': x = 2; y = 0; break;
        case '4': x = 0; y = 1; break;
        case '5': x = 1; y = 1; break;
        case '6': x = 2; y = 1; break;
        case '7': x = 0; y = 2; break;
        case '8': x = 1; y = 2; break;
        case '9': x = 2; y = 2; break;
        case '0': x = 1; y = 3; break;
        default: x = 0; y = 3; // '#'
    }
    return make_pair(x, y);
}

int main() {
    string number;
    cin >> number;
    
    int total_moves = 0;
    for (int i = 1; i < number.size(); i++) {
        pair<int, int> cur = coord(number[i - 1]);
        pair<int, int> next = coord(number[i]);
        total_moves++;
        total_moves++;
        if (cur.first == next.first) {
            total_moves--;
        }
        if (cur.second == next.second) {
            total_moves--;
        }
    }
    cout << total_moves << endl;
    return 0;
}
