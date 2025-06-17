//  You had to kill me, but it killed you just the same
//  Cursing my name, wishing I stayed
//  You turned into your worst fears

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
    int n, m;
    cin >> n >> m;
    int x = n / 2 + 1;
    int y = m / 2 + 1;
    vector<tuple<int, int, int, int>> arr(n * m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            arr[i * m + j - m - 1] = { max(abs(x - i), abs(y - j)), abs(x - i) + abs(y - j), i, j };
        }
    }
    sort(arr.begin(), arr.end());
    dbg(arr);
    for (auto [a, b, c, d] : arr) {
        cout << c << " " << d << nl;
    }

    cout << nl;
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
// problem-url: https://codeforces.com/contest/2118/problem/E
