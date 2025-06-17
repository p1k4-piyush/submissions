//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I

#include "bits/stdc++.h"
#include <queue>
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
#define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

void evermore()
{
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n, 0);
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        ll tt = arr[i];
        ll t2 = 1;
        while (t2 <= max(tt, k)) {
            if (tt & t2) {
                ans++;
            } else {
                pq.push(t2);
            }
            t2 <<= 1;
        }
    }
    dbg(pq);
    dbg(ans);
    while (!pq.empty() && k >= pq.top()) {
        k -= pq.top();
        pq.pop();
        ans++;
    }

    cout << ans;

    cout << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PIKA
    auto album_start_time = std::chrono::high_resolution_clock::now();
#endif
    int number_of_albums = 1;
    cin >> number_of_albums;
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 2000
// problem-url: https://codeforces.com/contest/2118/problem/C
