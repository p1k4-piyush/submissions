//  Time, mystical time
//  Cuttin' me open then healing me fine
//  Were there clues I didn't see?

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

//  https://github.com/the-tourist/algo/blob/master/data/hashmap.cpp

// #include <bits/extc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

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

// template <typename K, typename V, typename Hash = splitmix64_hash>
// using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;

// template <typename K, typename Hash = splitmix64_hash>
// using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;
typedef unordered_map<long long, int, splitmix64_hash> safe_map;

void evermore()
{
    int n;
    cin >> n;

    safe_map t;
    int tt;
    for (int i = 0; i < n; i++) {
        cin >> tt;
        t[tt] = i;
    }
    dbg(t);

    cout << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while (number_of_albums--) {
        evermore();
    }
    return 0;
}
