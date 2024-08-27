////
//// Created by smetanka on 23.04.24.
////
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
using ll = long long;

const int k = 26;  // alphabet
vector<string> mas;
size_t curpos = 0;

struct Vertex {
    Vertex* to[k] = {0};  // nullptr means no transition
    bool terminal = false;
};

Vertex *root = new Vertex();

void add_string(string &s) {
    Vertex *v = root;
    for (char c : s) {
        int cc = c - 'a';
        if (!v->to[cc]) {
            v->to[cc] = new Vertex();
        }
        v = v->to[cc];
    }
    v->terminal = true;
}

void dfs(Vertex *v, string &s) {
    if (v->terminal) {
        cout << s;
        if (curpos < mas.size()) {
            cout << mas[curpos];
        }
        curpos++;
    }
    for (int i = 0; i < k; i++) {
        if (v->to[i]) {
            s.push_back(i + 'a');
            dfs(v->to[i], s);
            s.pop_back();
        }
    }
}

int main() {
    string input;
    cin >> input;

    vector<string> output;

    bool st = false;
    string word = "", tchk = "";
    if (input[0] == '.') {
        st = true;
    }

    for (char c : input) {
        if (c == '.') {
            tchk += '.';
            if (!word.empty()) {
//                add_string(word);
                output.push_back(word);
                word = "";
            }
        } else {
            word += c;
            if (!tchk.empty()) {
                mas.push_back(tchk);
                tchk = "";
            }
        }
    }
    if (!word.empty()) {
        output.push_back(word);
//        add_string(word);
    }
    if (!tchk.empty()) {
        mas.push_back(tchk);
    }
    if (st) {
        cout << mas[curpos];
        curpos++;
    }

//
    sort(output.begin(), output.end());
    for (string s : output) {
        cout << s;
        if (curpos < mas.size()) {
            cout << mas[curpos];
        }
        curpos++;
    }
//    string s;
//    dfs(root, s);
    if (curpos < mas.size()) {
        cout << mas[curpos];
    }
    return 0;
}
