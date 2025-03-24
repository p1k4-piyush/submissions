//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green

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
int n,m;
set<pair<int,int>> arr;

void solve(){
	cin >> n >> m;
    int ans = 0;
    int u,v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
        if (u == v){
            ans++;
            continue;
        }
        pair<int,int> t = {min(u,v),max(u,v)};
        if (arr.count(t)){
            ans++; continue;
        }
        arr.insert(t);
	}

    cout << ans;
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



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc393/tasks/abc393_c
