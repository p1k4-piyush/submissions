//  I think I've seen this film before
//  And I didn't like the ending 
//  You're not my homeland anymore
//  So what am I defending now?

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
vector<bool> ans;

void dfs(vector<vector<int>> &G,int v, int p){
    ans[v] = true;
    for(auto i:G[v]){
        if(ans[i]){
            continue;
        }
        dfs(G,i,v);
    }
}
void solve(){
	int n; cin >> n;
	vector<int> a(n),b(n),a1(n),b1(n);
    
    iota(all(a1),1);
    iota(all(b1),1);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(all(a1),[&](int i,int j){
        return a[i-1]<a[j-1];
    });
    sort(all(b1),[&](int i,int j){
        return b[i-1]<b[j-1];
    });

    vector<vector<int>> G(n);

    for(int i = 0; i < n-1; i++){
        G[a1[i]-1].push_back(a1[i+1]-1);
    }
    
    for(int i = 0; i < n-1; i++){
        G[b1[i]-1].push_back(b1[i+1]-1);
    }
    ans.assign(n,false);
    ans[a1[n-1]-1] = true;
    dfs(G,a1[n-1]-1,a1[n-1]-1);

    dbg(a1);
    dbg(b1);
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



// time-limit: 1000
// problem-url: https://codeforces.com/contest/1608/problem/C
