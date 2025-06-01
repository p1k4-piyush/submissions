//  But I'm a fire and I'll keep your brittle heart warm
//  If your cascade ocean waves blues come
//  All these people think love's for show
//  But I would die for you in secret

#include <bits/stdc++.h>
#include <queue>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

string s;
int n;

void solve()
{
    cin >> s;
    n = s.size();
    vector<int> arr(26, 0);
    set<int> st;

    for (int i = 0; i < n; i++) {
        arr[s[i] - 'A']++;
        st.insert(s[i] - 'A');
    }

    string ans;
    int mx = *max_element(arr.begin(), arr.end());
    if (2 * mx - 1 > n) {
        cout << "-1" << nl;
        return;
    }

    int t = 100;
    while (2 * mx - 1 < n) {
        int t2 = *st.begin();
        st.erase(st.begin());
        arr[t2]--;
        ans += char('A' + t2);
        if (t != 100 && arr[t]) {
            st.insert(t);
        }
        t = t2;
        mx = *max_element(arr.begin(), arr.end());
        n--;
    }
    if (mx) {
        string ss;
        t = max_element(arr.begin(), arr.end()) - arr.begin();
        ans += char('A' + t);
        for (int i = 0; i < 26; i++) {
            if (i == t)
                continue;
            for (int j = 0; j < arr[i]; j++) {
                ans += char('A' + i);
                ans += char('A' + t);
            }
        }
    }

    cout << ans << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1743
