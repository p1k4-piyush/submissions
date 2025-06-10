//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'

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

void evermore()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = -1, r = n;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] > s[i + 1]) {
            l = i;
            break;
        }
    }
    if (l == -1) {
        cout << s << nl;
        return;
    }

    for (int i = l + 1; i < n; i++) {
        if (s[i] > s[l]) {
            r = i;
            break;
        }
    }
    dbg(l);
    dbg(r);
    char tt = s[l];

    for (int i = l; i < r; i++) {
        s[i] = s[i + 1];
    }
    s[r - 1] = tt;

    cout << s << nl;
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
// problem-url: https://atcoder.jp/contests/abc409/tasks/abc409_d
