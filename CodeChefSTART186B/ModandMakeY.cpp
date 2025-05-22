//  Bold was waitress on our three year trip
//  Getting lunch down by the lakes
//  She said I looked like an American singer

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

int n,x,y;
vector<bool> dp;
vector<int> arr;

void solve(){
    cin >> n >> x >> y;

    arr.assign(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp.assign(x+1,0);
    dp[x] = 1;

    vector<int> ans;
    queue<int> q;
    q.push(x);
    vector<int> dp2;      

    for(int i = 0; i < n; i++){
        int t = arr[i];
        if(t <= y){
            break;
        }
        for(int j = t; j <= x; j++){
            if(dp[j] && (!dp[j%t])){
                dp[j%t] = true;
                q.push(j%t);
            }
        }
        dp2.push_back(t);
        while(!q.empty()){
            t = q.front(); 
            q.pop();
            for(int j : dp2){
                if((t >= j) && (!dp[t%j])){
                    dp[t%j] = true;
                    q.push(t%j);
                }
            }
        }
        
        if(dp[y]){
            ans.push_back(i+1);
        }
    }

    
    cout << ans.size() << nl;
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
// problem-url: https://www.codechef.com/START186B/problems/MODMAKEY
