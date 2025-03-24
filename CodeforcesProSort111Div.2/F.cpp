//  I'm not your problem anymore
//  So what am I defending now?
//  You were my crown
//  Now I'm in exile, seein' you out

#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;

void solve(){
	int n,m; cin >> n >> m;
    int mn = INT_MAX, mx = -1, tt = INT_MAX;
    vector<vector<pair<int,int>>> G(n);
	for(int i = 0; i < m; i++){
        int a,b,w;
		cin >> a >> b >> w;
        G[a-1].push_back({b-1,w});
        G[b-1].push_back({a-1,w});
        mx = max(mx,w); mn = min(mn,w);
	}
    for(int i = 0; i < n; i++){
        for(auto j: G[i]){
            for(auto k:G[j.first]){
                if(i==k.first){ continue; }
                tt = min(tt,j.second+k.second);
            }
        }
    }
    int ans = -1;
    int lo = mn, hi = min(mx+1,tt),mid;
    while(hi >= lo){
        mid = (hi+lo+1)/2;

    vector<int> side(n, -1);
    bool is_bipartite = true;
    queue<int> q;
    for (int st = 0; st < n; ++st) {
        if (side[st] == -1) {
            q.push(st);
            side[st] = 0;
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (auto u2 : G[v]) {
                    if(u2.second>mid){
                        continue;
                    }
                    int u = u2.first;
                    if (side[u] == -1) {
                        side[u] = side[v] ^ 1;
                        q.push(u);
                    } else {
                        is_bipartite &= side[u] != side[v];
                    }
                }
            }
        }
    }

        if(!is_bipartite){
            ans = mid;
            hi = mid-1;
        }else{
            lo = mid+1;
        }

    }
	cout << ((ans>0)?ans:tt) <<  nl;
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



// time-limit: 4000
// problem-url: https://codeforces.com/group/0U62CQraSv/contest/580866/problem/F
