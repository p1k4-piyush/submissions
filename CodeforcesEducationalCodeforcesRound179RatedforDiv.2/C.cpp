//  I think I've seen this film before
//  And I didn't like the ending
//  You're not my homeland anymore
//  So what am I defending now?

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
    int n;
    cin >> n;
    vector<ll> ans(n + 1, 0);
    vector<ll> arr(n + 1, 0);
    ll cur = 0;
    ll prev = -1;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == prev) {
            cur++;
        } else {
            cur = 1;
            prev = arr[i];
        }
        ans[arr[i]] = max(ans[arr[i]], cur);
    }
    ll a = inf;
    for (ll i = 1; i <= n; i++) {
        if (ans[i] != 0) {
            a = min(a, i * (n - ans[i]));
        }
    }

    cout << a << nl;
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
