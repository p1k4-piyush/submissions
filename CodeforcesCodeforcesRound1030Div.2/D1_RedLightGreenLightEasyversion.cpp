//  I didn't have it in myself to go with grace
//  And so the battleships will sink beneath the waves
//  You had to kill me, but it killed you just the same

#include "bits/stdc++.h"
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
#define int ll

const ll inf = ll(1000000000000000);
const char nl = '\n';

int k;
int checkr(int i, int dir, int tmod)
{
    return ((i - 1) * 2 + dir) * k + tmod;
};
void evermore()
{
    int n;
    cin >> n >> k;
    vector<int> p(n + 2, 0);
    vector<int> d(n + 2, 0);
    p[0] = 0;
    d[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    p[n + 1] = inf + 1;
    d[n + 1] = -1;

    int m = n * 2 * k;

    vector<vector<int>> G(m);
    vector<char> possible(m, 0);
    deque<int> qu;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            for (int kk = 0; kk < k; kk++) {
                int dir2 = j;
                if (kk == d[i])
                    dir2 ^= 1;

                int t = (dir2 == 1 ? i + 1 : i - 1);
                ll dist = abs(p[t] - p[i]);
                int t2 = (kk + dist % k) % k;

                int u = checkr(i, j, kk);
                if (t == 0 || t == n + 1) {
                    if (!possible[u]) {
                        possible[u] = 1;
                        qu.push_back(u);
                    }
                } else {
                    int v = checkr(t, dir2, t2);
                    G[v].push_back(u);
                }
            }
        }
    }

    while (!qu.empty()) {
        int v = qu.front();
        qu.pop_front();
        for (int i : G[v]) {
            if (!possible[i]) {
                possible[i] = 1;
                qu.push_back(i);
            }
        }
    }

    int q;
    cin >> q;
    while (q--) {
        ll x;
        cin >> x;
        int idx = int(lower_bound(p.begin() + 1, p.begin() + 1 + n, x) - (p.begin() + 1)) + 1;
        bool c = false;
        if (idx <= n && p[idx] == x) {
            int tt = checkr(idx, 1, 0);
            c = possible[tt];
        } else {
            int tt = int(upper_bound(p.begin() + 1, p.begin() + 1 + n, x) - p.begin());
            if (tt > n) {
                c = true;
            } else {
                ll dist = (p[tt] - x) % k;
                int s = checkr(tt, 1, int(dist));
                c = possible[s];
            }
        }
        cout << (c ? "YES" : "NO") << nl;
    }

    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PIKA
    auto album_start_time = std::chrono::high_resolution_clock::now();
#endif
    int number_of_albums = 1;
    cin >> number_of_albums;
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 4000
// problem-url: https://codeforces.com/contest/2118/problem/D1
