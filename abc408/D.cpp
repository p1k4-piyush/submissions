//  'Cause I knew you
//  Steppin' on the last train
//  Marked me like a bloodstain, I

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
    string s;
    cin >> s;
    dbg(count(s.begin(), s.end(), '1'));
    ll a = inf, b = inf;
    for (auto i : s) {
        ll tt = ((i == '1') ? -1 : 1);
        a = min(a + tt, tt);
        b = min(a, b);
    }
    cout << count(s.begin(), s.end(), '1') + min(ll(0), b);

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
