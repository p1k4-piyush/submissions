//  Gold was color of the leaves
//  When I showed you around Centennial Park
//  Hell was the journey but it brought me heaven

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
    int p, s;
    cin >> p >> s;
    {
        int t = gcd(p, s);
        p /= t;
        s /= t;
    }
    if (p > 4 * s) {
        cout << -1 << nl;
        return;
    }

    if (p > 2 * s) {
        int x = 0;
        while (x < 50001 && ((1 + x) * p != s * (4 + 2 * x))) {
            x++;
        }
        if (x == 50001) {
            cout << -1 << nl;
            return;
        }
        x++;
        cout << x << nl;
        for (int i = 0; i < x; i++) {
            cout << 0 << " " << i << nl;
        }
        return;
    }

    if (p == 2 * s) {
        cout << 4 << nl;
        cout << 0 << " " << 0 << nl;
        cout << 0 << " " << 1 << nl;
        cout << 1 << " " << 0 << nl;
        cout << 1 << " " << 1 << nl;
        return;
    }

    int t = (p - 1) / 2;
    p -= 2 * t;
    s -= t;

    if (p == 2) {
        cout << 4 * s * s + 4 * s * t << nl;
        for (int i = 0; i < 2 * s; i++) {
            for (int j = 0; j < 2 * s; j++) {
                cout << i << " " << j << nl;
            }
        }
        for (int i = 0; i < 4 * s * t; i++) {
            cout << 0 << " " << i + s + s << nl;
        }
    } else {
        cout << 16 * s * s + 16 * s * t << nl;
        for (int i = 0; i < 4 * s; i++) {
            for (int j = 0; j < 4 * s; j++) {
                cout << i << " " << j << nl;
            }
        }
        for (int i = 0; i < 16 * s * t; i++) {
            cout << 0 << " " << i + s + s + s + s << nl;
        }
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
// problem-url: https://codeforces.com/contest/2111/problem/F
