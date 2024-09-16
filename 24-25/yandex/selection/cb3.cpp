#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    int k, can_delete = 0;
    bool can_add = false;
    cin >> str >> k;

    for (auto elem : str) {
        if (elem == '?' || elem == '*') {
            can_delete++;
        }
        if (elem == '*') {
            can_add = true;
        }
    }

    if (k < str.length() - 2 * can_delete || (k > str.length() - can_delete && (!can_add))) {
        cout << "Impossible";
        return 0;
    }

    vector<char> str_res(k);
    if (k <= str.length() - can_delete) {
        int need_del = str.length() - can_delete - k, cur_index = 0;
        for (auto elem : str) {
            if (need_del > 0 && (elem == '?' || elem == '*')) {
                need_del--;
                cur_index--;
            } else if (elem != '?' && elem != '*') {
                str_res[cur_index] = elem;
                cur_index++;
            }
        }
    } else {
        int need_add = k - str.length() + can_delete, cur_index = 0;
        for (auto elem : str) {
            if (elem == '*' && can_add) {
                char need = str_res[cur_index - 1];
                while (need_add--) {
                    str_res[cur_index] = need;
                    cur_index++;
                }
                can_add = false;
            } else if (elem != '?' && elem != '*') {
                str_res[cur_index] = elem;
                cur_index++;
            }
        }
    }

    for (auto elem : str_res) {
        cout << elem;
    }
    
    return 0;
}