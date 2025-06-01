//  But there's robbers to the east, clowns to the west
//  I'd give you my sunshine, give you my best
//  But the rain is always gonna come if you're standing with me

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
vector<int> arr;

void solve()
{
    cin >> n;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> s;
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound(arr[i]);
        if (it != s.begin()) {
            it--;
            s.erase(it);
        }
        dp[i] = n - s.size();
    }
    s.clear();
    for (int i = 1; i <= n; i++) {
        s.insert(i);
    }
    vector<int> dp2(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        auto it = s.upper_bound(arr[i]);
        if (it != s.begin()) {
            it--;
            s.erase(it);
        }
        dp2[i] = n - s.size();
    }
    dbg(dp);
    dbg(dp2);
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += min(dp[i], dp2[i + 1]);
    }

    cout << ans << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// time-limit: 4000
// problem-url: https://codeforces.com/contest/2101/problem/C
