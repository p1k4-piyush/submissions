//  Rebekah rode up on the afternoon train, it was sunny
//  Her saltbox house on the coast took her mind off St. Louis

#include <bits/stdc++.h>
using namespace std;

// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


typedef long long ll;
#define all(x) (x).begin(), (x).end()
const ll INF = ll(4e18) + 5;
const ll MOD = 1000000007;
const char nl = '\n';

#define dbg(...)

#include <boost/container/flat_set.hpp>
#include <ext/pb_ds/assoc_container.hpp>

// ----------------------------------------------------------------
// no other typedefs changed — we'll just swap out ordered_set for flat_set
// ----------------------------------------------------------------

const ll MAX_N = 2e5+100;
ll n;
vector<pair<ll,ll>> arr;

void solve(){
    cin >> n;
    arr.resize(n);

    for(ll i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    sort(all(arr));

    // -- here: use flat_set instead of ordered_set --
    boost::container::flat_set<ll> L, R;
    for(ll i = 0; i < n; i++){
        R.insert(arr[i].second * n + i);
    }

    ll ans = 0, ans_x = 0, ans_y = 0;

    for(ll i = 1; i < n; i++){
        ll y1 = arr[i-1].second * n + (i-1);
        R.erase(y1);
        L.insert(y1);

        if (arr[i].first == arr[i-1].first) continue;

        ll lo = 0, hi = min(i/2, (n-i)/2), mid;
        ll y = 0, ans1 = 0;
        while(hi >= lo){
            mid = (hi + lo) / 2;
            bool c = false;
            ll lo1 = -1e9, hi1 = 1e9, cur = 0, mid1;
            while(hi1 >= lo1){
                mid1 = (hi1 + lo1) / 2;
                // replace order_of_key(...) :
                ll l1 = distance(L.begin(), L.lower_bound(mid1 * n));
                ll l2 = i - l1;
                ll r1 = distance(R.begin(), R.lower_bound(mid1 * n));
                ll r2 = (n - i) - r1;

                if (l1 < mid) {
                    lo1 = mid1 + 1;
                } else if (l2 < mid) {
                    hi1 = mid1 - 1;
                } else if (r1 < mid) {
                    lo1 = mid1 + 1;
                } else if (r2 < mid) {
                    hi1 = mid1 - 1;
                } else {
                    c = true;
                    cur = mid1;
                    break;
                }
            }
            if (c) {
                ans1 = mid;
                y = cur;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (ans1 > ans) {
            ans = ans1;
            ans_x = arr[i].first;
            ans_y = y;
        }
    }

    cout << ans << nl;
    cout << ans_x << " " << ans_y << nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2046/C
