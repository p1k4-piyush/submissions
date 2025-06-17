//  The wedding was charming, if a little gauche
//  There's only so far as new money goes
//  They picked out a home and called it "Holiday House"

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
    int n;
    cin >> n;
    int t = 1;
    cout << 2 * n - 1 << nl;
    // cout << t << " 1 " << n << nl;
    // t++;
    for (int i = 1; i <= n; i++) {
        cout << t << " 1 " << i << nl;
        if (i + 1 <= n) {
            cout << t << " " << i + 1 << " " << n << nl;
        }
        t++;
    }

    // cout << nl;
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
// problem-url: https://codeforces.com/contest/2118/problem/B
