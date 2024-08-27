//
// Created by smetanka on 23.04.24.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;

//int countPalindromeSubstrings(const string& s) {
//    int count = 0;
//    int n = s.length();
//    const int p = 31;
//
//    // Считаем префиксные хеши
//    vector<ll> p_pow(n);
//    p_pow[0] = 1;
//    for (int i = 1; i < n; ++i) {
//        p_pow[i] = p_pow[i - 1] * p;
//    }
//
//    vector<ll> hashes(n);
//    for (int i = 0; i < n; ++i) {
//        hashes[i] = (s[i] - 'a' + 1) * p_pow[i];
//        if (i) hashes[i] += hashes[i - 1];
//    }
//
//    // Подсчет палиндромных подстрок
//    for (int center = 0; center < n; ++center) {
//        int left = center;
//        int right = center;
//        while (left >= 0 && right < n) {
//            ll hash_left = hashes[left];
//            ll hash_right = hashes[right];
//            if (left > 0) hash_left -= hashes[left - 1];
//
//            if (hash_left * p_pow[right - left] == hash_right) {
//                count++;
//            } else {
//                break;
//            }
//
//            left--;
//            right++;
//        }
//    }
//
//    return count;
//}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    const int p = 31;
    const int mod = 1e9 + 7;
    size_t n = s.length(), shift = 0;

    vector<ll> p_pow(n);
    p_pow[0] = 1;
    for (size_t i = 1; i < n; i++) {
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    }

    vector<ll> h(n);
    for (size_t i = 0; i < n; i++) {
        h[i] = ((s[i] - 'a' + 1) * p_pow[i]) % mod;
        if (i) {
            h[i] += h[i - 1];
            h[i] %= mod;
        }
    }

    vector<ll> h_reverse(n);
    reverse(s.begin(), s.end());
    for (size_t i = 0; i < n; i++) {
        h_reverse[i] = ((s[i] - 'a' + 1) * p_pow[i]) % mod;
        if (i) {
            h_reverse[i] += h[i - 1];
            h_reverse[i] %= mod;
        }
    }
    reverse(h_reverse.begin(), h_reverse.end());

    int result = 0, l, r, mid;
    ll ht, hr;
    for (size_t cur = 0; cur < n; cur++) {
        //  сначала бинпоиск по нечётным палиндромам
        l = -1, r = min(cur, n - cur);
        while (r - l != 1) {
            mid = l + (r - l) / 2;

            ht = h[cur];
            if (cur - mid) ht -= h[cur - mid - 1];
            hr = h_reverse[cur];
            if (cur + mid != n - 1) hr -= h_reverse[cur + mid + 1];

            if ((cur < n - 1 - cur && ht * p_pow[n - 1 - cur - cur] == hr) || (n - 1 - cur <= cur && hr * p_pow[cur - n + 1 + cur])) {
                l = mid;
            } else {
                r = mid;
            }
        }
        result += r + 1;
        // затем бинпоиск по чётным палиндромам
        l = -1, r = min(cur, n - cur + 1);
        while (r - l != 1) {
            mid = l + (r - l) / 2;

            ht = h[cur];
            if (cur - mid) ht -= h[cur - mid - 1];
            hr = h_reverse[cur + 1];
            if (cur + mid + 1 != n - 1) hr -= h_reverse[cur + mid + 2];

            if ((cur < n - 2 - cur && ht * p_pow[n - 2 - cur - cur] == hr) || (n - 2 - cur <= cur && hr * p_pow[cur - n + 2 + cur])) {
                l = mid;
            } else {
                r = mid;
            }
        }
        result += r;
    }

    cout << result;

    return 0;
}

