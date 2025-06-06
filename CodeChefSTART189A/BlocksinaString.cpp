//  We gather here, we line up, weepin' in a sunlit room
//  And if I'm on fire, you'll be made of ashes tooi

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<pair<int, int>> v;
    char prev = s[0];
    int t = 0;
    int cur = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] == '?') {
            // s[i] = '0';
            t++;
            continue;
        }
        if (t > 0) {
            if (s[i] == prev) {
                if (s[i] == '1') {
                    v.push_back({ t, -2 });
                } else {
                    v.push_back({ t, 2 });
                }
                t = 0;
                continue;
            } else {
                v.push_back({ t, 0 });
                t = 0;
            }
        }
        prev = s[i];
    }
    prev = '9';
    assert(s.size() == n);
    assert(s[0] != '?');
    assert(s[n - 1] != '?');
    for (int i = 0; i < n; i++) {
        char t = s[i];
        if (t == '?') {
            t = '0';
        }
        if (t != prev) {
            cur++;
        }
        prev = t;
        dbg(cur);
    }
    sort(v.begin(), v.end(), [&](auto i, auto j) {
        if (i.second != j.second) {
            return i.second < j.second;
        } else {
            if (i.second == -2) {
                return i.first < j.first;
            }
            return i.first > j.first;
        }
    });
    dbg(v);

    int tt = count(s.begin(), s.end(), '1');
    for (int i = 0; i < tt; i++) {
        cout << -1 << " ";
    }
    cout << cur << " ";
    int tt2 = count(s.begin(), s.end(), '?');
    int j = 0;
    int idx = 0;
    while (j < tt2) {
        auto t = v[idx];
        idx++;

        cur += max(t.second, 0);
        dbg(make_pair(t.first, t.second));
        for (int i = 0; i < t.first; i++) {
            if (i == t.first - 1) {
                cur += min(t.second, 0);
            }
            cout << cur << " ";
            // if (i == t.first - 1) {
            //     cur += min(t.second, 0);
            // }
        }
        j += t.first;
        // v.erase(v.size() - 1);
    }
    dbg(v);
    for (int i = 0; i < n - tt - tt2; i++) {
        cout << -1 << " ";
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
// problem-url: https://www.codechef.com/START189A/problems/BLOCKSTR
