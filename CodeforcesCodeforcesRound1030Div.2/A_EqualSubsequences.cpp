//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

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
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cout << 1;
    }
    for (int i = 0; i < n - k; i++) {
        cout << 0;
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
// problem-url: https://codeforces.com/contest/2118/problem/A
