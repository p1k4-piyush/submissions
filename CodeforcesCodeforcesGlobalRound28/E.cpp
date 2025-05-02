//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet


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

const int MAX_N = 1000+100;
int arr[2*MAX_N][MAX_N];

void solve(){
	int n,m; cin >> n >> m;
	if (2*n - 1 >= m){
        cout << "YES" << nl;
        FOR(i,2*n){
            FOR(j,m){
                cout << ((i+j)%(2ll*n))/2 + 1 << " ";
            }
            cout << nl;
        }
    }else{
        cout << "NO" << nl;
    }
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
// problem-url: https://codeforces.com/contest/2048/problem/E

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2048/problem/E
