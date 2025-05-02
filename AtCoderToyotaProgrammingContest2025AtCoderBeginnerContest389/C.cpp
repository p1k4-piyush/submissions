//  We were something, don't you think so?
//  Rosé flowing with your chosen family
//  And it would've been sweet
//  If it could've been me

#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int ll;

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
ll arr[MAX_N];

void solve(){
	int n; cin >> n;
    int t; ll tt;
    int idx = 0;
    int j = 1;
    arr[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> t;
        if (t == 1){
            cin >> tt;
            arr[j] = arr[j-1]+tt;
            j++;
        }else if (t == 2){
            idx++;
        }else{
            cin >> tt;
            cout << arr[tt+idx-1] - arr[idx] << nl;
        }
	}

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
// problem-url: https://atcoder.jp/contests/abc389/tasks/abc389_c
