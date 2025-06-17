//  Betty, I'm here on your doorstep
//  And I planned it out for weeks now but
//  It's finally sinking in
//  Betty, right now is the last time
//  I can dream about what happens when you see my face again
//  The only thing I want to do
//  Is make it up to you

#include "bits/stdc++.h"
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
#define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

void evermore()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> arr(n, vector<char>(m));
    int ans = 0;
    vector<vector<int>> arr2(n, vector<int>(m, 0));
    char t;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t;
            if (t == '.') {
                arr[i][j] = 1;
            } else if (t == '#') {
                arr[i][j] = 0;
            } else {
                arr[i][j] = 0;
                arr2[i][j] = 1;
                ans++;
            }
        }
    }

    vector<vector<int>> pre_sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++) {
        ll t = 0;
        for (int j = 0; j < m; j++) {
            t += arr2[i][j];
            pre_sum[i + 1][j + 1] = pre_sum[i][j + 1] + t;
        }
    }

    auto get = [&](int x1, int y1, int x2, int y2) -> int {
        x1 = max(x1, int(0));
        y1 = max(y1, int(0));
        x2 = min(x2, n - 1);
        y2 = min(y2, m - 1);
        return pre_sum[x2 + 1][y2 + 1] - pre_sum[x1][y2 + 1] - pre_sum[x2 + 1][y1] + pre_sum[x1][y1];
    };

    int mn = ans;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j]) {
                mn = min(mn, get(i - k + 1, j - k + 1, i + k - 1, j + k - 1));
            }
        }
    }

    cout << ans - mn << nl;
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
// time-limit: 2000
// problem-url: https://codeforces.com/contest/2113/problem/C
