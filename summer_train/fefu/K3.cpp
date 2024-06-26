#include <vector>
#include <fstream>
using namespace std;
using ll = long long;

ll n, full; // n - количество блюд, full - минимально необходимый уровень сытости
vector<pair<ll, ll>> v; // v - вектор, хранящий пары (цена, коэффициент сытости) для каждого блюда
vector<bool> ready; // ready - вектор, который будет отслеживать, были ли уже рассчитаны значения стоимости для каждого уровня сытости
vector<ll> value; // value - вектор, который будет хранить минимальную стоимость для достижения определенного уровня сытости

// Рекурсивная функция для вычисления минимальной стоимости для достижения уровня сытости coef
ll solve(ll coef) { 
    // Базовый случай: Если coef меньше или равно нулю, то нам не нужно выбирать блюда, и стоимость равна 0
    if (coef <= 0) 
        return 0;
    // Проверка кэша: Если значение value[coef] уже рассчитано (ready[coef] == true), то просто возвращаем его
    if (ready[coef]) 
        return value[coef];
    ll best = 1e10; // Инициализируем best (минимальную стоимость) очень большим значением
    for (auto elem : v) // Цикл по всем блюдам
    {
        // Вычисляем минимальную стоимость для достижения уровня сытости coef с учетом текущего блюда
        best = min(best, solve(coef - elem.second) + elem.first); 
    }

    // Помечаем ready[coef] как true, так как мы рассчитали минимальную стоимость для уровня сытости coef
    ready[coef] = true; 
    // Записываем минимальную стоимость в value[coef]
    value[coef] = best; 

    return best; // Возвращаем минимальную стоимость для достижения уровня сытости coef
}

int main() {
    ifstream input("input.txt"); // Открываем входной файл
    ofstream output("output.txt"); // Открываем выходной файл

    input >> n >> full; // Считываем количество блюд (n) и минимально необходимый уровень сытости (full)
    v.resize(n); // Выделяем память для вектора v

    value.resize(100 * n); // Выделяем память для вектора value
    ready.resize(100 * n); // Выделяем память для вектора ready

    for (int i = 0; i < n; i++) {
        input >> v[i].first >> v[i].second; // Считываем цену и коэффициент сытости для каждого блюда
    }
    output << solve(full); // Вычисляем минимальную стоимость для достижения уровня сытости full и записываем результат в выходной файл
}
