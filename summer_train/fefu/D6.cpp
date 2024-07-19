#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int ans = 0; // количество максимально возможных съеденных шашек противника
vector<pair<int, int>> path(100); // максимальный путь
vector<pair<int ,int>> cur_path(100); // текущий путь
int cur_x, cur_y; // координаты текущей чёрной шашки, которую проверяем

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int n;
    input >> n;

    vector<vector<int>> mas(n + 2, vector<int> (n + 2, -1)); // доска, если -1 - пустая, -2 - белая, неотрицательные числа - черные
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            input >> c;
            if (c == 'X') {
                mas[i][j] = 0;
            } else if (c == 'O') {
                mas[i][j] = -2;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (mas[i][j] == 0) {
                cur_x = i;
                cur_y = j;
                bfs(mas, 0);
            }
        }
    }

    input.close();
    output.close();
    return 0;
}