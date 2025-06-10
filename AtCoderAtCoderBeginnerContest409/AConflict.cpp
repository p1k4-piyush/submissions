//  But I knew you'd linger like a tattoo kiss
//  I knew you'd haunt all of my what-ifs
//  The smell of smoke would hang around this long
//  'Cause I knew everything wehn I was young

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
    string a, t;
    cin >> a >> t;
    for (int i = 0; i < n; i++) {
        if (a[i] == 'o' && t[i] == 'o') {
            cout << "Yes" << nl;
            return;
        }
    }

    cout << "No" << nl;
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
// problem-url: https://atcoder.jp/contests/abc409/tasks/abc409_a
