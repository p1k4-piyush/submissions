//  Bad was the blood on the song in the cab
//  On your first trip to LA
//  You ate at my favorite spot for dinner

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
    int n, q;
    cin >> n >> q;
    vector<int> arr(n, 0);
    iota(arr.begin(), arr.end(), 1);
    dbg(arr);
    int k = 0;
    int t;
    for (int i = 0; i < q; i++) {
        cin >> t;
        dbg(arr);
        if (t == 1) {
            int tt, tt2;
            cin >> tt2 >> tt;
            arr[(tt2 - 1 + k) % n] = tt;
        } else if (t == 2) {
            int tt;
            cin >> tt;
            cout << arr[(tt - 1 + k) % n] << nl;
        } else {
            int tt;
            cin >> tt;
            k += tt;
            k %= n;
        }
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
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc410/tasks/abc410_c
