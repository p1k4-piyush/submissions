//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define int ll
const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n;
vector<int> arr;

void solve(){
	cin >> n;
	arr.assign(n,0);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    vector<int> pre(n,0);
    pre[0] = (arr[0]>0)?arr[0]:0;
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + ((arr[i]>0)?arr[i]:0);
    }

    vector<int> suf(n,0);
    suf[n-1] = (arr[n-1]<0)?-arr[n-1]:0;
    for(int i = n-2; i>=0; i--){
        suf[i] = suf[i+1] + ((arr[i]<0)?-arr[i]:0);
    }
    int ans = max(pre[n-1],suf[0]);
    for(int i = 1; i < n; i++){
        if (arr[i-1]>0 && arr[i]<0){
            ans = max(ans,pre[i-1]+suf[i]);
        }
    }


	cout << ans << nl;
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



// time-limit: 3000
// problem-url: https://codeforces.com/contest/2064/problem/C
