//  Vintage tee, brand new phone
//  High heels on cobblestones
//  When you are young, they assume you know nothing

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
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        g = gcd(g, arr[i]);
    }
    int m = *max_element(arr.begin(), arr.end());
    vector<int> dp(m + 1, 1e9);
    for (int i = 0; i < n; i++) {
        dp[arr[i]] = 0;
        for (int j = m; j >= 0; j--) {
            int t = gcd(j, arr[i]);
            dp[t] = min(dp[t], dp[j] + 1);
        }
    }
    dbg(dp);
    dbg(dp[g]);

    cout << n + dp[g] - (dp[g] ? 1 : 0) - count(arr.begin(), arr.end(), g);
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
// time-limit: 2000
// problem-url: https://codeforces.com/contest/2116/problem/C
