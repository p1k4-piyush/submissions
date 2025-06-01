//  Salt air, and the rust on your door
//  I never needed anything more
//  Whispers of "Are you sure?"
//  "Never have I have before"

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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int t = min(a, c);
    int t2 = min(b, d);
    if (t >= t2) {
        cout << "Gellyfish";
    } else {
        cout << "Flower";
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
// problem-url: https://codeforces.com/contest/2116/problem/A
