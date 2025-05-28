//  'Cause I knew you
//  Steppin' on the last train
//  Marked me like a bloodstain, I

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll          INF = ll(4e18) + 5;
const int         MOD = 1000000007;
const char        nl  = '\n';

#ifdef DEBUG
#include "/home/dbg/debug.cpp"
#else
#define dbg(...)
#endif

const int MAX_N = 2e5 + 100;
int       arr[MAX_N];
int       arr2[MAX_N];
int       ans[MAX_N];
int       ans2[MAX_N];

void solve()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    sort(arr, arr + n);
    sort(arr2, arr2 + m);
    int lo, hi;
    int x = 0, y;
    int k = 0;
    while (x <= min(n / 2, m))
    {
        k = max(k, x + min(n - 2 * x, (m - x) / 2));
        x++;
    }
    cout << k << nl;
    for (int i = 1; i <= n / 2; i++)
    {
        if (i == 0)
        {
            ans[i] = (arr[n - i - 1] - arr[i]);
        }
        ans[i] = ans[i - 1] + (arr[n - i] - arr[i - 1]);
    }
    for (int i = 1; i <= m / 2; i++)
    {
        if (i == 0)
        {
            ans2[i] = (arr2[m - i - 1] - arr2[i]);
        }
        ans2[i] = ans2[i - 1] + (arr2[m - i] - arr2[i - 1]);
    }

    x = 0;
    y = 0;
    for (int i = 1; i <= k; i++)
    {
        int t  = min(n - i, i);
        int t2 = min(m - i, i);
        if (x >= t)
        {
            cout << ans[t] + ans2[i - t] << " ";
            continue;
        }
        if (y >= t2)
        {
            cout << ans[i - t2] + ans2[t2] << " ";
            continue;
        }
        if (ans[x + 1] - ans[x] >= ans2[y + 1] - ans2[y])
        {
            x++;
        }
        else
        {
            y++;
        }

        cout << ans[x] + ans2[y] << " ";
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
    while (t--)
    {
        solve();
    }
    return 0;
}

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2063/problem/D

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2063/problem/D
