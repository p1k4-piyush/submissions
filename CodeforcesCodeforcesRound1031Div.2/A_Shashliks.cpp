//  And they said
//  "There goes the last great American dynasty
//  Who knows, if she never showed up, what could've been
//  There goes the maddest woman this town has ever seen
//  She had a marvelous time ruining everything"

#include "bits/stdc++.h"
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
    int k, a, b, x, y;
    cin >> k >> a >> b >> x >> y;
    int ans = 0;
    if (x < y) {
        int t = (k - a) / x;
        t = max(0, t);
        ans += t;
        k -= x * t;
        if (k >= a) {
            k -= x;
            ans++;
        }
        t = (k - b) / y;
        t = max(0, t);
        ans += t;
        if (k >= b) {
            k -= y;
            ans++;
        }
    } else {
        int t = (k - b) / y;
        t = max(0, t);
        ans += t;
        k -= y * t;
        if (k >= b) {
            k -= y;
            ans++;
        }
        dbg(k);
        dbg(ans);
        t = (k - a) / x;
        t = max(0, t);
        ans += t;
        if (k >= a) {
            k -= x;
            ans++;
        }
    }
    cout << ans << nl;
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
// time-limit: 1000
// problem-url: https://codeforces.com/contest/2113/problem/A
