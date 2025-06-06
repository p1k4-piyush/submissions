//  Vintage tee, brand new phone
//  High heels on cobblestones
//  When you are young, they assume you know nothing

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;
// #define int ll

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
    vector<int> a(k), b(k);

    for (int i = 0; i < k; i++) {
        cout << "? " << i + 1 << nl;
        cout.flush();
        cin >> a[i];
    }

    for (int i = n - k; i < n; i++) {
        cout << "? " << i + 1 << nl;
        cout.flush();
        cin >> b[i % k];
    }
    dbg(a);
    dbg(b);

    if (a == b) {
        if (n == k + k) {
            cout << "! " << k << " " << k << nl;
            cout.flush();
            return;
        }
        cout << "! " << -1 << nl;
        cout.flush();
        return;
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
// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2108/D
