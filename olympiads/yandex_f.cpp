//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//struct seg{
//    int stx, sty, fx, fy, count;
//};
//
//int main() {
//    int n, curx, cury;
//    bool flag;
//    cin >> n;
//    vector<seg> fdiaglr;
//    vector<seg> fdiagrl;
//    vector<seg> fgoriz;
//    vector<seg> fvertik;
//    vector<seg> sdiagrl;
//    vector<seg> sdiaglr;
//    vector<seg> sgoriz;
//    vector<seg> svertik;
//    for (int i = 0; i < n; i++) {
//        cin >> curx >> cury;
//        if (i % 2 == 0) {
//            flag = true;
//            for (seg &s : fdiaglr) {
//                if (curx + 1 == s.stx && cury - 1 == s.sty) {
//                    s.stx = curx;
//                    s.sty = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx - 1 == s.fx && cury + 1 == s.fy) {
//                    s.fx = curx;
//                    s.fy = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "First";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                fdiaglr.push_back(ns);
//            }
//
//
//            flag = true;
//            for (seg &s : fdiagrl) {
//                if (curx - 1 == s.stx && cury - 1 == s.sty) {
//                    s.stx = curx;
//                    s.sty = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx + 1 == s.fx && cury + 1 == s.fy) {
//                    s.fx = curx;
//                    s.fy = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "First";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                fdiagrl.push_back(ns);
//            }
//
//            flag = true;
//            for (seg &s : fgoriz) {
//                if (curx + 1 == s.stx && cury == s.sty) {
//                    s.stx = curx;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx - 1 == s.fx && cury == s.fy) {
//                    s.fx = curx;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "First";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                fgoriz.push_back(ns);
//            }
//
//
//            flag = true;
//            for (seg &s : fvertik) {
//                if (curx == s.stx && cury + 1 == s.sty) {
//                    s.sty = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx == s.fx && cury - 1 == s.fy) {
//                    s.fy = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "First";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                fvertik.push_back(ns);
//            }
//        } else {
//            flag = true;
//            for (seg &s : sdiaglr) {
//                if (curx + 1 == s.stx && cury - 1 == s.sty) {
//                    s.stx = curx;
//                    s.sty = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx - 1 == s.fx && cury + 1 == s.fy) {
//                    s.fx = curx;
//                    s.fy = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "Second";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                sdiaglr.push_back(ns);
//            }
//
//
//            flag = true;
//            for (seg &s : sdiagrl) {
//                if (curx - 1 == s.stx && cury - 1 == s.sty) {
//                    s.stx = curx;
//                    s.sty = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx + 1 == s.fx && cury + 1 == s.fy) {
//                    s.fx = curx;
//                    s.fy = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "Second";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                sdiagrl.push_back(ns);
//            }
//
//            flag = true;
//            for (seg &s : sgoriz) {
//                if (curx + 1 == s.stx && cury == s.sty) {
//                    s.stx = curx;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx - 1 == s.fx && cury == s.fy) {
//                    s.fx = curx;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "Second";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                sgoriz.push_back(ns);
//            }
//
//
//            flag = true;
//            for (seg &s : svertik) {
//                if (curx == s.stx && cury + 1 == s.sty) {
//                    s.sty = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (curx == s.fx && cury - 1 == s.fy) {
//                    s.fy = cury;
//                    s.count++;
//                    flag = false;
//                }
//                if (s.count == 5) {
//                    if (i == n - 1) {
//                        cout << "Second";
//                        return 0;
//                    }
//                    cout << "Inattention";
//                    return 0;
//                }
//            }
//            if (flag) {
//                seg ns;
//                ns.fx = curx;
//                ns.fy = cury;
//                ns.count = 1;
//                ns.stx = curx;
//                ns.sty = cury;
//                svertik.push_back(ns);
//            }
//        }
//    }
//    for (seg s : fdiagrl) {
//        cout << "\n" << s.stx << " " << s.sty << " " << s.fx << " " << s.fy << " " << s.count;
//    }
//    cout << "Draw";
//    return 0;
//}



//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//    int n, cx, cy, c;
//    cin >> n;
//    vector<vector<pair<short int, short int>>> pole(1e18, vector<pair<short int, short int>> (1e18, make_pair(-1, -1)));
//    for (int i = 0; i < n; i++) {
//        cin >> cx >> cy;
//        pole[cx + 1e9][cy + 1e9].first = i % 2;
//        pole[cx + 1e9][cy + 1e9].first = i;
//    }
//    for (int i = 0; i < 1e18; i++) {
//        for (int j = 0; j < 1e18; j++) {
//            if (pole[i][j].first != -1) {
//                c = pole[i][j].first;
//
//            }
//        }
//    }
//    return 0;
//}


#include <iostream>
#include <deque>
using namespace std;
using ll = long long;
int main() {
    int n, k, x;
    cin >> n >> k;
    deque<int> min_of_queue;
    deque<int> queuemain;
    for (int i = 0; i < k; i++) {
        cin >> x;
        queuemain.push_back(x);
        while (!min_of_queue.empty() && min_of_queue.back() > x) {
            min_of_queue.pop_back();
        }
        min_of_queue.push_back(x);
    }
    cout << min_of_queue.front() << " ";
    for (int i = 0; i < n - k; i++) {
        if (!min_of_queue.empty() && queuemain.front() == min_of_queue.front()) {
            min_of_queue.pop_front();
        }
        queuemain.pop_front();
        cin >> x;
        queuemain.push_back(x);
        while (!min_of_queue.empty() && min_of_queue.back() > x) {
            min_of_queue.pop_back();
        }
        min_of_queue.push_back(x);
        cout << min_of_queue.front() << " ";
    }
    return 0;
}