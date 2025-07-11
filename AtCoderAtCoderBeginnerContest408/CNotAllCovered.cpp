//  Sequin smile, black lipstick
//  Sensual politics
//  When you are young, they assume you know nothing

#include <bits/stdc++.h>
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

int arr[int(1e6 + 100)];

void evermore()
{
    int n, m, l, r;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        arr[l - 1]++;
        arr[r]--;
    }

    partial_sum(arr, arr + n + 1, arr);
    cout << *min_element(arr, arr + n);
    cout << nl;
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
// problem-url: https://atcoder.jp/contests/abc408/tasks/abc408_c
