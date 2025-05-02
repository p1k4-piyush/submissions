//  But we were something, don't you think so?
//  Roaring 20s, tossing pennies in the pool
//  And if my wishes came true
//  It would've been you

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
int arr[MAX_N];

void solve(){
	int n; cin >> n;
	
    if (n%33){
        cout << "NO";
    } else{
        cout << "YES";
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



// time-limit: 1000
// problem-url: https://codeforces.com/contest/2048/problem/A
