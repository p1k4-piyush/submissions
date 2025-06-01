//  50 years is a long time
//  Holiday House sat quietly on that beach
//  Free of women with madness, their men and bad habits
//  And then it was bought by me

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

void evermore()
{
    ll a1, b1, c1, d1;
    cin >> a1 >> b1 >> c1 >> d1;
    __int128 a = a1, b = b1, c = c1, d = d1;

    for (__int128 q = 1; q < __int128(inf); q++) {
        __int128 tt = a * q / b;
        __int128 tt2 = c * q - ll(1);
        tt2 /= d;
        if (tt < tt2) {
            cout << ll(q) << nl;
            return;
        }
    }

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
// time-limit: 3000
