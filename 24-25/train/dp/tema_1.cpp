#include <iostream>
#include <string>

struct Node {
    std::pair<char, int> value;
    Node* next;
    Node* prev;
    Node(std::pair<char, int> value) {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class Stack {
private: int size = 0;
public: Node* start = nullptr;
public: Node* end = nullptr;
public: void push(std::pair<char, int> value) {
        Node* node = new Node(value);
        if (size == 0) {
            start = node;
            end = node;
        } else {
            end->next = node;
            node->prev = end;
            end = node;
        }
        ++size;
    }
public: std::pair<char, int> pop() {
        Node* deleted_node = end;
        if (end->prev != nullptr) {
            end = end->prev;
            end->next = nullptr;
        }
        --size;
        std::pair<char, int> value = deleted_node->value;
        delete [] deleted_node;
        return value;
    }
public: bool isEmpty() {
        return size == 0;
    }
public: std::pair<char, int> top() {
        return end->value;
    }
};

int main() {
    Stack st;
    std::pair<char, int> cur;
    std::string s;
    std::cin >> s;
    char elem = '@';
    int number = -1, index;

    for (char c : s) {
        if ((c > '9' || c < '0') && elem != '@') {
            if (number == -1) {
                    number = 1;
            }
            st.push(std::make_pair(elem, number));
            number = -1;
        }

        if (c <= 'Z' && c >= 'A') {
            elem = c;
        } else if (c == '(') {
            elem = '0'; 
        } else if (c == ')') {
            elem = '1';
        } else {
            if (number == -1) {
                number = c - '0';
            } else {
                number *= 10;
                number += c - '0';
            }
        }
    }

    if (elem != '0') {
        if (number == -1) {
                number = 1;
        }
        st.push(std::make_pair(elem, number));
    }


    Node* current = st.end;
    Stack pomosh;
    index = 1;
    while (current != nullptr) {
        if (current->value.first == '1') {
            index *= current->value.second;
            pomosh.push(std::make_pair('-', current->value.second));
        } else if (current->value.first == '0') {
            index /= pomosh.top().second;
            pomosh.pop();
        } else {
            current->value.second *= index;
        }
        current = current->prev;
    }

    for (char ans = 'A'; ans <= 'Z'; ans++) {
        current = st.start;
        number = 0;
        while (current != nullptr) {
            if (current->value.first == ans) {
                number += current->value.second;
            }
            current = current->next;
        }
        if (number == 1) {
            std::cout << ans;
        } else if (number != 0) {
            std::cout << ans << number;
        }
    }

    return 0;
}