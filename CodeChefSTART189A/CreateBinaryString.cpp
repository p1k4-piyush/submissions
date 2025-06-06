//  And they said
//  "There goes the last great American dynasty
//  Who knows, if she never showed up, what could've been
//  There goes the maddest woman this town has ever seen
//  She had a marvelous time ruining everything"

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
    ll n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ll t = i * a + (n - i) * b + (i * (n - i) * c);
        ans = max(ans, t);
    }

    for (ll i = 0; i <= n; i++) {
        ll t = i * a + (n - i) * b + (i * (n - i) * d);
        ans = max(ans, t);
    }

    cout << ans << nl;
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
// time-limit: 1000
// problem-url: https://www.codechef.com/START189A/problems/CREATEBINSTR
