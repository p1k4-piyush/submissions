//  The wedding was charming, if a little gauche
//  There's only so far as new money goes
//  They picked out a home and called it "Holiday House"

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
vector<int> l,r;
vector<vector<int>> G;

void solve(){
	cin >> n;
	l.assign(n,0);
    r.assign(n,0);
    G.assign(n,vector<int>());
	for(int i = 0; i < n; i++){
		cin >> l[i] >> r[i];
	}
    int u,v;
    for(int i = 0; i < n-1; i++){
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
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



// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2062/D
