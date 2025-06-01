//  Remember when I pulled up and said, "Get in the car"
//  And then canceled my plans, just in case you'd call
//  Back when I was livin' for the hope of it all
//  "Meet me behind the mall"

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

int n;
vector<ll> arr;

void solve()
{
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll mn = inf;
    for (ll i = 0; i < (1ll << n); i++) {
        ll cur = 0;
        ll cur2 = 0;
        for (ll j = 0; j < n; j++) {
            if (i & (1ll << j)) {
                cur += arr[j];
            } else {
                cur2 += arr[j];
            }
        }
        mn = min(mn, abs(cur - cur2));
    }

    cout << mn << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1623
