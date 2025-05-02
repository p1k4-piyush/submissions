//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing

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
	ll n; cin >> n;
    vector<vector<int>> G(n);
    int u,v;
    int arr[n] = {0};
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
	}
    ll t = 0;
    for(int i = 0; i < n; i++){
        if (G[i].size() == 1) t++;
    }

    ll ans = t*(n-t);
    t = 0;
    for(int i = 0; i < n; i++){
        for(auto j:G[i]){
            if (G[j].size()==1) arr[i]++;
        }

        if (arr[i] == 0 && G[i].size() > 1) t++;
    }
	
    for(int i = 0; i < n; i++){
        if (arr[i] > 0) ans += t*(G[i].size()-arr[i]-1);
    }
    
	cout << ans << nl;
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
// problem-url: https://codeforces.com/contest/2053/problem/E
