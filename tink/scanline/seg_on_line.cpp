#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

struct Event {
    int x;
    int type; // 0 - начало отрезка, 1 - конец отрезка
    int index;

    bool operator<(const Event& other) const {
        if (x == other.x) {
            return type < other.type;
        }
        return x < other.x;
    }
};

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> segments(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> segments[i].first >> segments[i].second;
    }

    std::vector<Event> events; // список событий
    for (int i = 0; i < N; ++i) {
        events.push_back({segments[i].first, 0, i}); // начало отрезка
        events.push_back({segments[i].second, 1, i}); // конец отрезка
    }

    std::sort(events.begin(), events.end()); // сортировка событий по X

    std::vector<int> result(N, -1); // результат для каждого отрезка, -1 означает отсутствие результата
    std::stack<int> stack; // стек для хранения непосредственно содержащихся отрезков

    for (const auto& event : events) {
        if (event.type == 0) { // начало отрезка
            stack.push(event.index);
        } else { // конец отрезка
            if (!stack.empty()) {
                int top = stack.top();
                stack.pop();
                if (stack.empty() || segments[top].second >= segments[stack.top()].second) {
                    result[event.index] = top;
                }
            }
        }
    }

    for (const auto& res : result) {
        std::cout << res + 1 << " "; // вывод результатов (+1 для приведения индексов к единой нумерации)
    }
    std::cout << std::endl;

    return 0;
}