//  Our coming-of-age has come and gone
//  Suddenly the summer, it's clear
//  I never had the courage of my convictions
//  As long as danger is near

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
    int n, q;
    cin >> n >> q;
    vector<int> b(n, 0);
    vector<tuple<int, int, int>> query(q, { 0, 0, 0 });

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> get<0>(query[i]) >> get<1>(query[i]) >> get<2>(query[i]);
        get<0>(query[i])--;
        get<1>(query[i])--;
        get<2>(query[i])--;
    }

    vector<int> a = b;
    reverse(query.begin(), query.end());
    for (auto [x, y, z] : query) {
        a[x] = max(a[x], a[z]);
        a[y] = max(a[y], a[z]);
        if (z != x && z != y) {
            a[z] = 1;
        }
    }
    reverse(query.begin(), query.end());
    vector<int> t = a;
    for (auto [x, y, z] : query) {
        t[z] = min(t[x], t[y]);
    }
    if (t == b) {
        for (auto& i : a) {
            cout << i << " ";
        }
    } else {
        cout << "-1";
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
// time-limit: 2000
// problem-url: https://codeforces.com/contest/2116/problem/D
