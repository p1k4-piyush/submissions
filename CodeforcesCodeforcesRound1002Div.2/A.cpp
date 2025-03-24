//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'

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

void solve(){
	int n; cin >> n;
	map<int,int> a;
    map<int,int> b;
    int t;
    
	for(int i = 0; i < n; i++){
		cin >> t;
        a[t]++;
	}
    for(int i = 0; i < n; i++){
		cin >> t;
        b[t]++;
	}
    int ans = 0;
    for(auto i:a){
        ans++;
        if (ans>=3){
            cout << "YES" << nl; return;
        }
    }
    int ans2 = 0;
    for(auto i:b){
        ans2++;
        if(ans2>=3){
            cout << "YES" << nl; return;
        }
    }
    if (ans == 2 && ans2 == 2){
        cout << "YES" << nl; return;
    }


	cout << "NO" << nl;
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
// problem-url: https://codeforces.com/contest/2059/problem/A
