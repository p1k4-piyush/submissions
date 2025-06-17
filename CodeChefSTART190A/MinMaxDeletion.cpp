//  Bad was the blood on the song in the cab
//  On your first trip to LA
//  You ate at my favorite spot for dinner

#include "bits/stdc++.h"
#include <numeric>
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
    int n, q;
    cin >> n >> q;
    vector<int> tt(n, 0);
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    ll ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        tt[i] = min(arr[i], arr[i + 1]);
    }
    ans = accumulate(tt.begin(), tt.end(), ll(0));
    int a, x;
    while (q--) {
        cin >> a >> x;
        a--;
        arr[a] = x;
        if (a > 0) {
            ans -= tt[a - 1];
            tt[a - 1] = min(arr[a - 1], arr[a]);
            ans += tt[a - 1];
        }
        if (a < n - 1) {
            ans -= tt[a];
            tt[a] = min(arr[a], arr[a + 1]);
            ans += tt[a];
        }
        cout << ans << nl;
    }

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
// problem-url: https://www.codechef.com/START190A/problems/MNMXDEL
