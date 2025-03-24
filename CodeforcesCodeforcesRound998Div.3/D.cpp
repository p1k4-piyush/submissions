//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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


void solve(){
	int n; cin >> n;
    bool c = 1;
    int x,y;
    cin >> x;
	for(int i = 1; i < n; i++){
		cin >> y;
        if (c && x > y) c = 0;
        if (c) x = y-x;
	}
    

	cout << (c?"YES":"NO") << nl;
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
// problem-url: https://codeforces.com/contest/2060/problem/D
