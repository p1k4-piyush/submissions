//  Rebekah rode up on the afternoon train, it was sunny
//  Her saltbox house on the coast took her mind off St. Louis

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n,a,b;

void solve(){
    cin >> n >> a >> b;
    dbg(n,a,b);
    
    int d = n-a-b;
    int cur = 1;
    vector<int> ans;

    for(int i = 1; i <= d; i++){
        ans.push_back(cur);
        cur++;
    }
    
    for(int i = 1; i <= b; i++){
        ans.push_back(n-b+i);
    }
    
    for(int i = 1; i <= a; i++){
        ans.push_back(cur);
        cur++;
    }
    
    dbg(ans);
    if(ans.size() != n){
        cout << "NO" << nl; return;
    }
    vector<bool> vis(n,0);
    int a1 = 0,b1 = 0,d1 = 0;
    for(int i = 0; i < n; i++){
        if (ans[i] > n || ans[i] <= 0 || vis[ans[i]-1]){
            cout << "NO" << nl; return;
        }
        vis[ans[i]-1] = 1;
        if(ans[i] > i+1){
            b1++;
        }else if (ans[i] < i+1){
            a1++;
        }else{
            d1++;
        }
    }
    dbg(a1,b1,d1);
    if(a1!=a||b1!=b||d1!=d){
        cout << "NO" << nl;
        return;
    }
    
    
    cout << "YES" << nl;
    for(int i = 1; i <= n; i++){
        cout << i << " ";
    }
    cout << nl;
    for(auto i:ans){
        cout << i << " ";
    }
    cout << nl;

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
// problem-url: https://cses.fi/problemset/task/3399
