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
int arr[MAX_N];

void solve(){
	int m,k; cin >> m >> k;
    char t;
    int c = 0;
	
	for(int i = 0; i < m; i++){
		cin >> t;
        if (t == 'S'){
            c++;
        }
	}


	cout << m+k-c+1 << nl;
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
// problem-url: https://www.codechef.com/START171B/problems/SWISHGAME
