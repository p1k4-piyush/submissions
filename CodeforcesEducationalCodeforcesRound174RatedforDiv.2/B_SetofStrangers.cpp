//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet

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

void solve(){
	cin >> n >> m;
    map<int,set<pair<int,int>>> mp;
    int t;
    map<int,int> mp2;
	for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> t;
            mp[t].insert({i,j});
            mp2[t] = 0;
        }
	}
    
    dbg(mp);
    int mx = 1;
    for(auto i:mp){
        int c = 1;
        for(auto j:i.second){
            if (i.second.count({j.first+1,j.second}) > 0|| i.second.count({j.first,j.second+1}) > 0){
                c=2; 
                mx= 2;
                break;
            }
        }   
        mp2[i.first] = c;
    }
    dbg(mp2);
    int ans = 0;
    for(auto i:mp2){
        ans += i.second;
    }


	cout << ans - mx << nl;
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
// problem-url: https://codeforces.com/contest/2069/problem/B
