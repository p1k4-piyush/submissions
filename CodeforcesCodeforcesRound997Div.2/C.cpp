//  You're not my homeland anymore
//  So what am I defending now?
//  You were my town
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
	int n; cin >> n;
	
    if (n == 6){
        cout << "1 1 2 3 1 2\n"; return;
    }	
    for(int i = 0; i < (n+1)/2; i++) cout << i + 1 << " ";
    for(int i = 0; i < n/2; i++) cout << i + 1 << " ";
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
// problem-url: https://codeforces.com/contest/2056/problem/C
