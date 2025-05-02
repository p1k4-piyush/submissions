//  Second, third, and hundreth chances
//  Balancin' on breaking branches
//  Those eyes add insult to injury

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n,k,d;
vector<int> arr;

void solve(){
    cin >> n >> k >> d;
    arr.assign(n,0);
    priority_queue<int,vector<int>,greater<int>> pq; 
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> rem;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }
    ll ans = 0;
    int cur = n;
    for(int i = 1; i <= d; i++){

        while(!rem.empty() && i>=rem.top().first){
            pq.push(rem.top().second);
            rem.pop();
            cur++;
        }

        while(cur > k){
            ans++;
            rem.push({i+pq.top(),pq.top()});
            pq.pop();
            cur--;
        }
    }
    
    
    cout << ans << nl;
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


// time-limit: 1000
// problem-url: https://www.codechef.com/START182B/problems/DPF
