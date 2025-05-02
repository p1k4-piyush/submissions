//  sequin smile, black lipstick
//  sensual politics
//  when you are young, they assume you know nothing

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const ll inf = ll(4e18) + 5;
const int mod = 1000000007;
const char nl = '\n';

#ifdef debug 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int max_n = 2e5+100;
int arr[max_n];

void solve(){
	int n; cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    
    int a = arr[0];
    int rn = arr[1];
    int rd = arr[0];
    bool c = 1;
    for(int i = 1; i < n; i++){
        if((arr[i-1]*rn)%rd==0 && arr[i] == arr[i-1]*rn/rd) continue;
        c = 0; break;
    }

	cout << (c?"Yes":"No") << nl;
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
// problem-url: https://atcoder.jp/contests/abc390/tasks/abc390_b
