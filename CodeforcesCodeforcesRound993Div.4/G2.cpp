//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'


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

const int MAX_N = 2e5+100;
int arr[MAX_N];
int dp[MAX_N];
int deg[MAX_N];

void solve(){
	int n; cin >> n;
    int t;
    fill(dp,dp+n,1);
    fill(deg,deg+n,0);
    
    FOR(i,n){
    	cin >> t;
        arr[i] = t-1;
        deg[t-1]++;
	}

    queue<int> q;
    FOR(i,n){
        if (deg[i]==0){
            q.push(i);
        }
    }
    int ans = 0;
    while(!q.empty()){
        t = q.front();
        q.pop();
        ans = max(ans,dp[t]);
        dp[arr[t]] += dp[t];
        deg[arr[t]]--;
        if (deg[arr[t]] == 0){
            q.push(arr[t]);
        }
    }
	
    cout << ans+2 << nl;
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
// problem-url: https://codeforces.com/contest/2044/problem/G2
