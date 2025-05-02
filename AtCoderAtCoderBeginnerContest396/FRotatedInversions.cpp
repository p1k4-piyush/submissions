//  And you can aim for my heart, go for blood
//  And you would still miss me in your bones
//  And I still talk to you
//  And when you can't sleep at night (you hear my stolen lullabies)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

void add(vector<int>& BIT, int idx, int val){
    idx += 1;
    while(idx < BIT.size()){
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

int query(vector<int>& BIT, int idx){
    idx += 1;
    int sum = 0;
    while(idx){
        sum += BIT[idx];
        idx &= idx - 1;
    }
    return sum;
} 

int CountInversions(vector<int> a, int n){
    vector<int> BIT(n + 1, 0);
    vector<int> b = a;
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    }
    // now for all i, 0 <= a[i] < n
    int inv_count = 0;
    for(int i = 0; i < n; i++){
        // increasing index a[i] by 1
        add(BIT, a[i], 1);
        // count of numbers greater than a[i] before it
        // being added to the inverse count
        inv_count += i - query(BIT, a[i]) + 1;
    }
    return inv_count;
}

const int MAX_N = 1e5+100;
vector<int> arr;

void solve(){
    int n,m;
    cin >> n >> m;
    arr.assign(n,0);
    vector<ll> freq(m,0);
    vector<ll> sum1(m,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
        sum1[arr[i]] += i+1;
    }

    ll x = CountInversions(arr,n);
    vector<ll> dp(m,0);
    for(int i = 0; i < m; i++){
        dp[i] = 2 *sum1[i] - freq[i]*(n+1);
    }

    
    reverse(all(dp));
    for(int i = 1; i < m; i++){
        dp[i] += dp[i-1];
    }
    cout << x << nl;
    for (int i = 1; i < m;i++){
        cout << x + dp[i-1] << nl;
    }
        
    
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc396/tasks/abc396_f
