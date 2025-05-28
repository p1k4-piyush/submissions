//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

const ll   INF = ll(4e18) + 5;
const int  MOD = 1000000007;
const char nl  = '\n';

#ifdef DEBUG
#include "/home/dbg/debug.cpp"
#else
#define dbg(...)
#endif

const int MAX_N = 2e5 + 100;
int       arr[MAX_N];

void solve()
{
    int n;
    cin >> n;
    int                 u, v;
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int mx  = -1;
    int idx = -1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = G[i].size();
        if (arr[i] > mx)
        {
            mx  = arr[i];
            idx = i;
        }
    }
    int ans = mx;
    for (auto i : G[idx])
    {
        arr[i] -= 1;
    }
    arr[idx] = -1;
    mx       = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx)
        {
            mx  = arr[i];
            idx = i;
        }
    }
    cout << ans + mx - 1 << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2063/problem/C
