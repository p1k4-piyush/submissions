//  I guess you never know, never know
//  And if you wanted me, you really should have showed
//  And if you never bleed, you're never gonna grow
//  And it's alright now

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
int n,q;
vector<int> arr;
vector<int> pre;
vector<vector<int>> dp;

void solve(){
	cin >> n >> q;
	arr.assign(n,0);
    pre.assign(n+1,0);
    dp.assign(n,vector<int>(32,0));

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    
    pre[0] = arr[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1]^arr[i];
    }

    for(int i = 0; i < n; i++){
        if (i>0){
            dp[i] = dp[i-1];
        }
        dp[i][log2(arr[i])] = i;
        for(int j = 30; j >= 0; j--){
            dp[i][j] = max(dp[i][j],dp[i][j+1]);
        }
    }
    int tt,x;
    for(int t = 0; t < q; t++){
        cin >> tt;
        x = n-1;
        while(x >= 0 && tt>0){
            int t2 = log2(tt);
            int next = dp[x][t2];

            tt ^= pre[x]^pre[next];
            x = next;
            if (next == -1 || arr[next] > tt) break;
            tt ^= arr[next];
            x--;
        }
        cout << n - x - 1 << " ";
    }
    
    cout << nl;
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



// time-limit: 5000
// problem-url: https://codeforces.com/contest/2064/problem/D
