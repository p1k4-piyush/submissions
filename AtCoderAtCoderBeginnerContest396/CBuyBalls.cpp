//  Second, third, and hundreth chances
//  Balancin' on breaking branches
//  Those eyes add insult to injury

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,m;
vector<int> w,b;

void solve(){
    cin >> n >> m;
    b.assign(n,0);
    w.assign(m,0);

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    for(int i = 0; i < m; i++){
        cin >> w[i];
    }
    
    sort(all(b),greater<int>());
    sort(all(w),greater<int>());
    ll sum = 0;
    int t = 0;

    while(t < n && b[t]>=0){
        sum += b[t]; t++;
    }
    int tt = 0;
    while(tt < m && w[tt]>=0 && tt < t){
        sum += w[tt]; tt++;
    }
    while(t < n && tt < m && w[tt]+b[t] >= 0){
        sum += w[tt]+b[t];
        t++; tt++;
    }
        
    
    cout << sum <<  nl;
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
// problem-url: https://atcoder.jp/contests/abc396/tasks/abc396_c
