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

const int MAX_N = 2e5+100;
int arr[MAX_N];

void solve(){
	int n; cin >> n;
    int e = 0, o = 0;	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        if (arr[i]&1){
            o++;
        }else{
            e++;
        }
	}
    

	cout << (o + ((e>0)?1:-1)) << nl;
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
// problem-url: https://codeforces.com/contest/2061/problem/A
