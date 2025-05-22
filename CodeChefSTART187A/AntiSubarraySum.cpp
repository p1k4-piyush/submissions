//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + ll(5);
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n,k;
vector<ll> arr;
vector<ll> B;

void solve(){

    cin >> n >> k;
    arr.assign(n,0);
    B.assign(n,0);
    for (ll i = 0; i < n; ++i) cin >> arr[i];
    for (ll i = 0; i < n; ++i) cin >> B[i];

    vector<ll> st;
    ll sum = 0;
    for (ll i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            st.push_back(i);
            sum += arr[i];
        }
    }

    sort(st.begin(), st.end());

    auto is_contiguous = [&]() {
        return !st.empty() && (st.back() - st.front() + 1 == (ll)st.size());
    };

    auto breakk = [&](ll protecc = -1) {
        if (st.size() <= 1) return;

        vector<bool> ccc(n, false);
        for (ll i : st) ccc[i] = true;

        ll l = st.front(), r = st.back();

        ll minA = inf;
        ll idx_rem = -1;
        for (ll i : st) {
            if (i == l || i == r || i == protecc) continue;
            if (arr[i] < minA) {
                minA = arr[i];
                idx_rem = i;
            }
        }

        ll sum_rem = (idx_rem != -1) ? sum - arr[idx_rem] : -inf;

        ll maxA = -inf;
        ll idx_add = -1;
        for (ll j = 0; j < n; ++j) {
            if (ccc[j]) continue;
            if (j == l - 1 || j == r + 1) continue;
            if (arr[j] > maxA) {
                maxA = arr[j];
                idx_add = j;
            }
        }

        ll sum_add = (idx_add != -1) ? sum + arr[idx_add] : -inf;

        if (sum_rem != -inf || sum_add != -inf) {
            if (sum_add >= sum_rem && idx_add != -1) {
                st.push_back(idx_add);
                sum = sum_add;
            } else if (idx_rem != -1) {
                st.erase(find(st.begin(), st.end(), idx_rem));
                sum = sum_rem;
            }
            sort(st.begin(), st.end());
            return;
        }

        auto fun2 = [&](bool ttt) {
            auto org = st;
            ll old_sum = sum;

            ll rem_idx = ttt ? st.front() : st.back();
            if (rem_idx == protecc) return false;

            if (ttt) {
                sum -= arr[st.front()];
                st.erase(st.begin());
            } else {
                sum -= arr[st.back()];
                st.pop_back();
            }

            vector<bool> tempp(n, false);
            for (ll i : st) tempp[i] = true;

            ll new_add = -1;
            ll bestA = -inf;
            ll newL = st.front(), newR = st.back();
            for (ll j = 0; j < n; ++j) {
                if (tempp[j]) continue;
                if (j == newL - 1 || j == newR + 1) continue;
                if (arr[j] > bestA) {
                    bestA = arr[j];
                    new_add = j;
                }
            }

            if (new_add != -1) {
                st.push_back(new_add);
                sum += arr[new_add];
                sort(st.begin(), st.end());
            }

            if (!is_contiguous()) return true;

            st = org;
            sum = old_sum;
            return false;
        };

        fun2(true); 
        fun2(false);
    };



    if (is_contiguous()) {
        breakk();
    }
    

    if (sum >= k) {
        cout << 0 << '\n';
        return;
    }

    bool has_inc = false;
    for (ll i : st) {
        if (B[i] == 1) {
            has_inc = true;
            break;
        }
    }

    if (has_inc) {
        cout << (k - sum) << '\n';
        return;
    }

    vector<bool> c(n, false);
    for (ll i : st) c[i] = true;

    ll bestA = -inf;
    ll idx_inc = -1;
    for (ll j = 0; j < n; ++j) {
        if (!c[j] && B[j] == 1) {
            if (arr[j] > bestA) {
                bestA = arr[j];
                idx_inc = j;
            }
        }
    }

    if (idx_inc != -1) {
        st.push_back(idx_inc);
        sum += arr[idx_inc];
        sort(st.begin(), st.end());
    }

    if (is_contiguous()) {
        breakk(idx_inc);
    }

    cout << (k - sum) << '\n';
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


// time-limit: 1000
// problem-url: https://www.codechef.com/START187A/problems/ANTISM
