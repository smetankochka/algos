#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

void bfs(int x, int y, vector<vector<int>>& mas, int cur_rec, vector<int>& size_rec) {
    mas[x][y] = cur_rec; // отмечаем что человек из группы
    size_rec[cur_rec]++; // увеличиваем размер этой группы на одного нашего человека

    // проверяем всех его соседей и запускаем рекурсию от них (нам надо чтобы сосед был, но ему еще не выдали группу)
    if (mas[x - 1][y] == -1){
        bfs(x - 1, y, mas, cur_rec, size_rec);
    }
    if (mas[x + 1][y] == -1) {
        bfs(x + 1, y, mas, cur_rec, size_rec);
    }
    if (mas[x][y - 1] == -1) {
        bfs(x, y - 1, mas, cur_rec, size_rec);
    }
    if (mas[x][y + 1] == -1) {
        bfs(x, y + 1, mas, cur_rec, size_rec);
    }
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int w, h;
    input >> w >> h;
    vector<vector<int>> mas(h + 2, vector<int> (w + 2, 0));// храним наш стадион, там где пусто будет лежать 0, там где сидит человек будем хранить номер его группы, в которой он может распространять звук (либо -1 если человеку группу еще не выдали)

    char c;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            input >> c;
            if (c == '#') {
                mas[i][j] = -1; // записываем те клетки, где занято
            }
        }
    }

    int cur_rec = 1; // текущая последняя обнаруженная группа, используем когда обнаруживаем новую группу
    vector<int> size_rec; // для каждой группы храним сколько человек в ней находится
    size_rec.push_back(0); // нулевая группа имеет размер ноль, так потом удобнее считать

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (mas[i][j] == -1) { // нашли человека из новой группы, которую еще не обходили
                size_rec.push_back(0); // добавляем площадь новой группы
                bfs(i, j, mas, cur_rec, size_rec); // вызываем рекурсивный обход из человека по соседям
                cur_rec++; // следующая группа будет уже с новым номером
            }
        }
    }

    int max_area = -1, ans_x, ans_y; // ответ
    int cur_area;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (!mas[i][j]) { // мы можем посадить туда агента только если пустая клетка
                cur_area = size_rec[mas[i][j - 1]];
                // далее добавляем в текущий размер только те группы, до которых еще не распространили
                if (mas[i][j - 1] != mas[i][j + 1]) {
                    cur_area += size_rec[mas[i][j + 1]];
                }
                if (mas[i][j - 1] != mas[i - 1][j] && mas[i][j + 1] != mas[i - 1][j]) {
                    cur_area += size_rec[mas[i - 1][j]];
                }
                if (mas[i][j - 1] != mas[i + 1][j] && mas[i][j + 1] != mas[i + 1][j] && mas[i - 1][j] != mas[i + 1][j]) {
                    cur_area += size_rec[mas[i + 1][j]];
                }

                if (cur_area > max_area) { // обновим максимум
                    max_area = cur_area;
                    ans_x = j;
                    ans_y = i;
                }
            }
        }
    }

    output << ans_x << " " << ans_y;

    input.close();
    output.close();
    return 0;
}
