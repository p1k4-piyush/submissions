//  Out of all the wrong arms right into that dive bar
//  Something wrapped all of my past mistakes in barbed wire
//  Chains around my demons, wool to brave the seasons
//  One single thread of gold tied me to you

#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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

//  https://github.com/the-tourist/algo/blob/master/data/hashmap.cpp

// #include <bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x)
    {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <typename K, typename V>
using HashMap = __gnu_pbds::gp_hash_table<K, V>;

// template <typename K, typename Hash = splitmix64_hash>
// using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;
typedef unordered_map<long long, int, splitmix64_hash> safe_map;

void evermore()
{
    int h, w;
    cin >> h >> w;
    bool swap1 = 0;
    if (h > w) {
        swap(h, w);
        swap1 = 1;
    }
    // vector<vector<int>> arr(h, vector<int>(w, 0));
    int arr[h][w];
    if (swap1) {
        char t;
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                cin >> t;
                arr[j][i] = (t == '.') ? 1 : -1;
            }
        }
    } else {
        char t;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> t;
                arr[i][j] = (t == '.') ? 1 : -1;
            }
        }
    }
    ll ans = 0;
    int col[w];
    for (int i = 0; i < h; i++) {
        fill(col, col + w, 0);
        for (int j = i; j < h; j++) {
            for (int k = 0; k < w; k++) {
                col[k] += arr[j][k];
            }

            ll ans1 = 0;
            HashMap<int, int> mp;
            mp[0] = 1;

            for (int k = 0; k < w; k++) {
                ans1 += col[k];
                auto it = mp.find(ans1);
                if (it != mp.end()) {
                    ans += it->second;
                    it->second++;
                } else {
                    mp[ans1] = 1;
                }
            }
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
// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc410/tasks/abc410_f
