//  Time, wonderous time 
//  Gave me the blues and then purple pink skies
//  And it's cool baby with me

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif


// Fenwick Tree for point updates and prefix‐sum queries
struct Fenwick {
    int n;
    vector<int> bit;
    Fenwick(int _n): n(_n), bit(n+1, 0) {}

    // add +v at index i
    void update(int i, int v=1) {
        for (; i <= n; i += i & -i)
            bit[i] += v;
    }

    // sum of [1..i]
    int query(int i) const {
        int s = 0;
        for (; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }
};

// Count inversions in arr (pairs i<j with arr[i]>arr[j])
long long countInversionsBIT(const vector<int>& arr) {
    int N = arr.size();
    if (N < 2) return 0;

    // 1) Coordinate‐compress values to [1..M]
    vector<int> vals(arr.begin(), arr.end());
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    // 2) Build Fenwick of size M
    Fenwick fw(vals.size());

    long long inv = 0;
    // 3) Traverse from right to left, counting how many seen elements < current
    for (int i = N - 1; i >= 0; --i) {
        // rank = position of arr[i] in vals + 1
        int r = int(lower_bound(vals.begin(), vals.end(), arr[i]) - vals.begin()) + 1;
        // all seen elements with rank < r are those < arr[i]
        inv += fw.query(r - 1);
        // mark current element as seen
        fw.update(r, 1);
    }
    return inv;
}

int n;
vector<int> arr;
string s;

void solve(){
    cin >> n;
    cin >> s;
    arr.assign(n,0);
    int t = 0;
    int t2 = 0;
    for(int i = 0; i < n; i++){
        arr[i] = (s[n-i-1]=='B');
        if(arr[i]){
            t2++;
        }
        if(arr[i]&&((n-i-1)&1)){
            t++;
        }
    }
    cout << (countInversionsBIT(arr)+abs((t2/2)-t))/2 << nl;
    
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2096/problem/E
