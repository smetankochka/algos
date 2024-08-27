#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Event {
    int place;
    int type;
    int originalIndex;
};

bool compareEvents(const Event &a, const Event &b) {
    if (a.place != b.place) {
        return a.place < b.place;
    } else {
        return a.type < b.type;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Event> events;
    for (int i = 0; i < n; ++i) {
        int start, end;
        cin >> start >> end;
        if (end < start) {
            swap(start, end);
        }
        events.push_back({start, 0, -1});
        events.push_back({end, 2, -1});
    }
    for (int i = 0; i < m; ++i) {
        int point;
        cin >> point;
        events.push_back({point, 1, i});
    }
    sort(events.begin(), events.end(), compareEvents);
    int count = 0;
    vector<int> result(m, 0);
    for (const Event &e : events) {
        if (e.type == 0) {
            ++count;
        } else if (e.type == 2) {
            --count;
        } else {
            result[e.originalIndex] = count;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << result[i] << " ";
    }
    return 0;
}