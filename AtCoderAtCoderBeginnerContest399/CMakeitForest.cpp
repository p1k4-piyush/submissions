//  What do sing on your drive home?
//  Do you see my face in the neighbor's lawn?
//  Does she smile?
//  Or does she mouth, "F*** you forever"

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/home/piyush/cpp_template_library/template/debug.cpp"
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

    cout << nl;
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

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc399/tasks/abc399_c
