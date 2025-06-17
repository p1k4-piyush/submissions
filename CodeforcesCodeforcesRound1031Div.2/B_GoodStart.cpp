//  Stood on the cliffside
//  Screaming "Give me a reason"
//  Your faithless love's the only hoax
//  I believe in

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
    int w, h, a, b, x1, y1, x2, y2;
    cin >> w >> h >> a >> b;
    cin >> x1 >> y1 >> x2 >> y2;

    if (((x1 != x2) && (abs(x1 - x2) % a == 0)) || ((y1 != y2) && (abs(y1 - y2) % b == 0))) {
        cout << "YES";
    } else {
        cout << "NO";
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
// time-limit: 1000
// problem-url: https://codeforces.com/contest/2113/problem/B
