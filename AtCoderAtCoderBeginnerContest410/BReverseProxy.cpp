//  Time, wonderous time
//  Gave me the blues and then purple pink skies
//  And it's cool baby with me

#include "bits/stdc++.h"
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

void evermore()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n, 0);
    int t;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t != 0) {
            arr[t - 1]++;
            cout << t << " ";
        } else {
            int mn = *min_element(arr.begin(), arr.end());
            for (int j = 0; j < n; j++) {
                if (arr[j] == mn) {
                    arr[j]++;
                    cout << j + 1 << " ";
                    break;
                }
            }
        }
    }

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
    // cin >> number_of_albums;
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc410/tasks/abc410_b
