//  We gather here, we line up, weepin' in a sunlit room
//  And if I'm on fire, you'll be made of ashes tooi

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

const int MAX_N = 12;
ll arr[MAX_N];

void solve(){
	int n; cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    set<ll> s; 
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i == j) continue;
            ll t = arr[i]&arr[j];
            s.insert(t);
        }
    }
    
	cout << s.size() << nl;
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



// time-limit: 3000
// problem-url: https://atcoder.jp/contests/abc390/tasks/abc390_d
