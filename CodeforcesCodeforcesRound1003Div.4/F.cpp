//  We always walked a very thin line
//  You didn't even hear me out
//  You never gave a warning sign
//  All this time

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n;
vector<int> arr;
vector<vector<int>> G;
vector<int> ans;

void dfs(int v, pair<int,int> p){
    if (p.first != -1 && arr[v] == arr[p.first]){
        ans[arr[v]-1]=1;
    }
    if (p.second != -1 && arr[v] == arr[p.second]){
        ans[arr[v]-1]=1;
    }
    for(auto i:G[v]){
        if (i == p.first){
            continue;
        }
        dfs(i,{v,p.first});
    }

}

void solve(){
	cin >> n;
	arr.assign(n,0);
    G.assign(n,vector<int>());
    ans.assign(n,0);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        arr[i]--;
	}
    int u,v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> tt(n,-1);
    for(int i = 0; i < n; i++){
        tt[arr[i]] = i;
        for (int j = 0; j < G[i].size(); j++){
            if(tt[arr[G[i][j]]] == i){
                ans[arr[G[i][j]]] = 1;
            }
            tt[arr[G[i][j]]] = i;
        }
    }
    dbg(ans);
    for(auto i:ans){
        cout << i;
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



// time-limit: 4000
// problem-url: https://codeforces.com/contest/2065/problem/F
