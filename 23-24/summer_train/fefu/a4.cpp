#include <fstream>
#include <algorithm>

using ll = long long;
using namespace std;
ifstream input("input.txt");
ofstream output("output.txt");

// Структура узла бинарного дерева поиска
struct Node {
    ll data;
    Node* left;
    Node* right;

    Node(ll data) : data(data), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева поиска
class BinarySearchTree {
private:
    Node* root;

    // Вставка узла в дерево
    Node* insert(Node* node, ll data) {
        if (node == nullptr) {
            return new Node(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        }
        return node;
    }

    // Удаление узла из дерева
    Node* remove(Node* node, ll data) {
        if (node == nullptr) {
            return nullptr;
        }
        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            // Узел с одним или без детей
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Узел с двумя детьми
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Нахождение минимального узла в дереве
    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Обход дерева в порядке возрастания
    void inorderTraversal(Node* node) {
        if (node != nullptr) {
            inorderTraversal(node->left);
            output << node->data << " ";
            inorderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Вставка значения в дерево
    void insert(ll data) {
        root = insert(root, data);
    }

    // Удаление значения из дерева
    void remove(ll data) {
        root = remove(root, data);
    }

    // Вывод дерева в порядке возрастания
    void printInOrder() {
        inorderTraversal(root);
    }
};

int main() {
    BinarySearchTree tree;
    ll number;
    // Чтение чисел из входного файла
    while (input >> number) {
        if (number > 0) {
            tree.insert(number);
        } else if (number < 0) {
            tree.remove(-number);
        } else if (number == 0) {
            tree.printInOrder();
            break;
        }
    }
    input.close();
    output.close();
    return 0;
}
