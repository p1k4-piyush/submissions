//  Even on my worst day, did I deserve, babe
//  All the hell you gave me?
//  'Cause I loved you, swear I loved you
//  'Til my dying day

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;
#define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

void evermore()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    vector<vector<int>> pos(k);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        pos[arr[i] - 1].push_back(i);
    }

    vector<vector<int>> dp(k);
    dp[k - 1].assign(pos[k - 1].size(), 0);

    for (int i = k - 2; i >= 0; i--) {
        int nn = pos[i + 1].size();
        dp[i].assign(pos[i].size(), inf);

        vector<int> dp1(nn), dp2(nn);

        dp1[0] = dp[i + 1][0] - pos[i + 1][0];
        for (int t = 1; t < nn; t++) {
            int val = dp[i + 1][t] - pos[i + 1][t];
            dp1[t] = min(dp1[t - 1], val);
        }

        dp2[nn - 1] = dp[i + 1][nn - 1] + pos[i + 1][nn - 1];
        for (int t = nn - 2; t >= 0; t--) {
            int val = dp[i + 1][t] + pos[i + 1][t];
            dp2[t] = min(dp2[t + 1], val);
        }

        for (int j = 0; j < pos[i].size(); j++) {
            int x = pos[i][j];
            int idx = upper_bound(pos[i + 1].begin(), pos[i + 1].end(), x) - pos[i + 1].begin() - 1;
            int tt = inf;
            if (idx >= 0) {
                tt = min(tt, dp1[idx] + x);
            }
            if (idx + 1 < nn) {
                tt = min(tt, dp2[idx + 1] - x);
            }
            dp[i][j] = tt;
        }
    }

    vector<int> ndp(n, inf);
    for (int i = 0; i < pos[0].size(); i++) {
        ndp[pos[0][i]] = dp[0][i];
    }

    vector<int> ans(n, inf);
    int t = inf;
    for (int i = 0; i < n; i++) {
        t = min(t, ndp[i] - i);
        ans[i] = t + i;
    }

    t = inf;
    for (int i = n - 1; i >= 0; i--) {
        t = min(t, ndp[i] + i);
        ans[i] = min(ans[i], t - i);
    }

    for (auto& i : ans) {
        cout << i << " ";
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
// time-limit: 1000
// problem-url: https://www.codechef.com/START189A/problems/NUMBERWALK
