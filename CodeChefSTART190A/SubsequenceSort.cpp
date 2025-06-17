//  Take the road less traveled by
//  Tell yourself you can always stop
//  What started in beautiful rooms
//  Ends with meetings in parking lots

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

bool check(const vector<int>& arr, int x)
{
    ll t = ((ll(1) << x) - ll(1));
    ll prev = 0;
    for (int i : arr) {
        ll tt = i;
        if (tt >= prev) {
            prev = tt;
        } else {
            if ((tt | t) < prev)
                return false;
            ll y = tt & ~t;
            ll c = 0;
            for (int j = x - 1; j >= 0; j--) {
                ll bit = ll(1) << j;
                ll c1 = (tt >> j) & 1;
                ll c2 = (prev >> j) & 1;
                if (c == 1) {
                    if (c1) {
                        y |= bit;
                    }
                } else {
                    if (c1 == c2) {
                        if (c1) {
                            y |= bit;
                        }
                    } else if (c1 == 1 && c2 == 0) {
                        y |= bit;
                        c = 1;
                    } else {
                        if ((t >> j) & ll(1)) {
                            y |= bit;
                        } else {
                            return false;
                        }
                    }
                }
            }
            prev = y;
        }
    }
    return true;
}
void evermore()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    bool c = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i - 1]) {
            c = 0;
            break;
        }
    }
    if (c) {
        cout << 0 << nl;
        return;
    }

    for (int i = 0; i < 33; i++) {
        if (check(arr, i)) {
            cout << (ll(1) << (i - 1)) << nl;
            return;
        }
    }

    cout << -1 << nl;
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
// problem-url: https://www.codechef.com/START190A/problems/ORSUBSORT
