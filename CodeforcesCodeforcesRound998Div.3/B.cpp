//  I knew you
//  Hand under my sweatshirt
//  Baby, kiss it better, I

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

const int MAX_N = 2000+100;
int arr[MAX_N][MAX_N];
int ans[MAX_N];
void solve(){
	int n,m; cin >> n >> m;
	bool c = 1;
	for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
		    cin >> arr[i][j];
        }
        if (!c) continue;
        sort(arr[i],arr[i]+m);
        int s = arr[i][0];
        for (int j = 1; j < m; j++){
		    if (arr[i][j] != s+j*n) c = 0;
        }
        ans[s]=i;
	}
    
    if (!c){ cout << "-1" << nl; return; }
    for(int i =0;i<n;i++) cout << ans[i]+1 << " ";
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2060/problem/B
