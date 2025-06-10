//  Your back beneath the sun
//  Wishin' I could write my name on it
//  Will you call when you're back at school?
//  I remember thinking I had you

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
    int n, l;
    cin >> n >> l;
    int cur = 0;

    vector<int> arr(l, 0);
    arr[cur] = 1;

    for (int i = 0; i < n - 1; i++) {
        int t;
        cin >> t;
        cur += t;
        cur %= l;
        arr[cur]++;
    }
    ll ans = 0;
    if (l % 3) {
        cout << 0 << nl;
        return;
    }
    for (int i = 0; i < l; i++) {
        int p1 = i;
        int p2 = (i + l / 3) % l;
        int p3 = (i + l / 3 + l / 3) % l;
        ans += arr[p1] * arr[p2] * arr[p3];
    }

    dbg(arr);
    cout << ans / 3 << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    while (number_of_albums--) {
        evermore();
    }
    return 0;
}
// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc409/tasks/abc409_c
