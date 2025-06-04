//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

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
    int n, m;
    cin >> n >> m;
    vector<int> arr(m, 0);

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int l = 0, r = m - 1;
    vector<pair<int, int>> ans;
    for (int i = 0; i < (n + 1) / 2; i++) {
        ans.push_back({ arr[l], arr[r] });
        ans.push_back({ arr[r], arr[l] });
        l++;
        r--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ans[i].first << " " << ans[i].second << " ";
        }
        cout << nl;
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
// time-limit: 3000
