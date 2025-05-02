//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define int ll
const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,m;
vector<vector<pair<int,int>>> G;


void solve(){
    cin >> n >> m;
    G.resize(n);
    int u,v,w;

    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        u--; v--;
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }

    int dp[32][n];
    memset(dp,-1,sizeof(dp));

    for (int bit = 0; bit < 32; bit++){
        for (int i = 0; i < n; i++){
            vector<int> cur;
            if (dp[bit][i] == -1){
                queue<int> q;
                q.push(i);
                cur.push_back(i);
                dp[bit][i] = 0;
                bool c = 1;
                while(c && !q.empty()){
                    int u = q.front(); q.pop();
                    for(auto i:G[u]){
                        int t = (i.second>>bit)&1;
                        if (dp[bit][i.first] == -1){
                            dp[bit][i.first]=dp[bit][u]^t;
                            q.push(i.first);
                            cur.push_back(i.first);
                        }else{
                            if (dp[bit][i.first]!=(dp[bit][u]^t)){
                                c = 0; break;
                            }
                        }
                    }
                }
                if (!c){
                    cout << "-1" << nl; return;
                }

                ll t = 0;
                for (auto i2:cur){
                    if (dp[bit][i2]) t++;
                }
                
                if (t > cur.size()-t){
                    for(auto i2:cur){
                        dp[bit][i2] ^= 1;
                    }
                }

            }
        }

    }
        
    for (int i = 0; i < 32; i++){
        int t = 0;
        for (int j = 0; j < n; j++){
            t += (dp[i][j]==1);
        }
        if (t>n-t){
            for(int j = 0; j < n; j++){
                dp[i][j] ^= 1;
            }
        }
    }
    vector<ll> ans(n,0);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < 32; j++){
            ans[i] += dp[j][i]<<j;
        }
    }
    for(auto i:ans){
        cout << i << " ";
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



// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc396/tasks/abc396_e
