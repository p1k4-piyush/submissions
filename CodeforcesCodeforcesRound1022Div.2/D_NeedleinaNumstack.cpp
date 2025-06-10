//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

map<int, int> mp;
int ask(int tt)
{
    if (mp.count(tt)) {
        return mp[tt];
    }
    cout << "? " << tt << nl;
    cout.flush();
    int t;
    cin >> t;
    mp[tt] = t;
    return t;
}

void evermore()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k, 0), b(k, 0);
    mp.clear();

    for (int i = 0; i < k; i++) {
        a[i] = ask(i + 1);
    }

    for (int i = 0; i < k; i++) {
        b[(n - i - 1) % k] = ask(n - i);
    }

    dbg(a);
    dbg(b);

    vector<int> diff;
    for (int i = 0; i < k; i++) {
        if (a[i] != b[i]) {
            diff.push_back(i);
        }
    }

    if (diff.size() == 0) {
        if (n == k + k) {
            cout << "! " << k << " " << k << nl;
            cout.flush();
            return;
        } else {
            cout << "! -1" << nl;
            cout.flush();
            return;
        }
    }

    int l = diff[0], r = (n - 1) / k * k + diff[0];
    while (r > l + k) {
        int mid = l + (r - l) / k / 2 * k;
        int t = ask(mid + 1);
        if (t == a[diff[0]]) {
            l = mid;
        } else {
            r = mid;
        }
    }
    dbg(l);
    dbg(r);

    int ll = 0, rr = diff.size();
    while (rr > ll + 1) {
        int mid = (ll + rr) / 2;
        int t = ask(l + diff[mid] - diff[0] + 1);
        if (t == a[diff[mid]]) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    dbg(ll);
    dbg(rr);

    int l1 = max(l - diff[0] + diff[ll], k - 1);
    int r1 = min(l - diff[0] + ((rr == diff.size()) ? (diff[0] + k) : diff[rr]), n - k);
    dbg(l1);
    dbg(r1);
    if (l1 + 1 != r1) {
        cout << "! " << -1 << nl;
        cout.flush();
        return;
    }

    cout << "! " << r1 << " " << n - r1 << nl;
    cout.flush();
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
// problem-url: https://codeforces.com/problemset/problem/2108/D
