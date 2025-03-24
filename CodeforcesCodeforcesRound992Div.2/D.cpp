//  And they said
//  "There goes the last great American dynasty
//  Who knows, if she never showed up, what could've been
//  There goes the maddest woman this town has ever seen
//  She had a marvelous time ruining everything"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,n) for (ll i = 0; i < n; ++i)
#define FOR2(i,n) for (ll i = n-1; i >= 0 ; --i)

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 1e6+100;
vector<int> ans;
int cur;
void dfs(vector<vector<int>> &G, int v, int p){
    for(auto i:G[v]){
        if (i == p){
            continue;
        }
        int t = cur+1;
        while(t != ans[v]+1 && (t%2 != ans[v]%2 || t-ans[v] == 2)){
            t++;
        }
        ans[i] = t;
        cur = t;
        dfs(G,i,v);
    }
    return;
}


void solve(){
	int n,a,b; cin >> n;
    vector<vector<int>> G(n);
    FOR(i,n-1){
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    ans.assign(n,0);
    cur = 1;
    ans[0] = 1;
    dfs(G,0,0);
    FOR(i,n){
        cout << ans[i] << " ";
    }
    cout << nl;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2040/problem/D
