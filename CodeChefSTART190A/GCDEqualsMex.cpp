//  Vintage tee, brand new phone
//  High heels on cobblestones
//  When you are young, they assume you know nothing

#include "bits/stdc++.h"
#include <algorithm>
using namespace std;

typedef int64_t ll;

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
    sort(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (binary_search(arr.begin(), arr.end(), i)) {
            int t = upper_bound(arr.begin(), arr.end(), i) - arr.begin();
            t = n - t;
            ans += pow(2, t);
        } else {

            break;
        }
    }

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
// time-limit: 2000
// problem-url: https://www.codechef.com/START190A/problems/GCDEQMEX
