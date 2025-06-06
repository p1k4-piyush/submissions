//  But I can see us lost in the memory
//  August slipped away into a moment of time
//  'Cause it was never mine

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
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int ans = 0;

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            bool c = 1;
            int cur = -1;
            for (int i = l; i <= r; i++) {
                if ((arr[i] - 1) / 2 <= cur) {
                    if (cur >= arr[i]) {
                        c = 0;
                        break;
                    } else {
                        cur = arr[i] - 1;
                    }
                }
                cur++;
            }
            ans += c;
            if (!c) {
                dbg(make_pair(l, r));
            }
        }
    }
    dbg("---");

    cout << ans << nl;
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
// problem-url: https://www.codechef.com/START189A/problems/SORTSUB7EZ
