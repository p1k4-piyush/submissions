//  And they called off the circus
//  Burned the disco down
//  When they sent home the horses
//  And the rodeo clowns

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

void evermore()
{
    ll n;
    cin >> n;

    ll cur = 1;
    ll ans = 2;
    while (cur < n) {
        cur <<= 1;
        cur++;
        ans += 2;
    }

    cout << ans + 1 << nl;
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
