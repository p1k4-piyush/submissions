//  Betty, I'm here on your doorstep
//  And I planned it out for weeks now but
//  It's finally sinking in
//  Betty, right now is the last time
//  I can dream about what happens when you see my face again
//  The only thing I want to do
//  Is make it up to you

#include "bits/stdc++.h"
#include <numeric>
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

void evermore()
{
    int n, h, m;
    cin >> n >> h >> m;
    vector<int> a(n, 0), b(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    vector<int> dp(h + 1, -1);
    dp[0] = m;

    for (int i = 0; i < n; i++) {
        vector<int> ndp(h + 1, -1);
        for (int j = 0; j <= h; j++) {
            if (dp[j] >= 0) {
                // hp
                if (j + a[i] <= h) {
                    ndp[j + a[i]] = max(ndp[j + a[i]], dp[j]);
                }
                // mag
                if (dp[j] >= b[i]) {
                    ndp[j] = max(ndp[j], dp[j] - b[i]);
                }
            }
        }
        int t = accumulate(ndp.begin(), ndp.end(), 0);
        if (t == -h - 1) {
            cout << i << nl;
            return;
        }
        dp = ndp;
    }

    cout << n << nl;
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
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc410/tasks/abc410_e
