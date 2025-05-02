//  Rebekah rode up on the afternoon train, it was sunny
//  Her saltbox house on the coast took her mind off St. Louis

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
ll n,q;
vector<int> arr;
vector<int> arr2;

void solve(){
	cin >> n >> q;
	arr.assign(q,0);
    arr2.assign(q,0);
    
    char tt;
	for(int i = 0; i < q; i++){
		cin >> arr[i] >> tt;
        arr[i]--;
        if (tt == '+'){
            arr2[i] = 1;
        }else{
            arr2[i] = 0;
        }
	}

    vector<vector<ll>> dist(n,vector<ll>(n,0ll));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            ll t = 0;
            ll ans = 0;
            for(int k = 0; k < q; k++){
                if (arr[k]==i && arr2[k]){
                    t++;
                }else if (arr[k]==j && !arr2[k]){
                    t--;
                }
                ans = max(t,ans);
            }
            dist[i][j] = ans+1ll;
        }
    } 
    
    dbg(dist);
    vector<vector<ll>> dp(pow(2ll,n)+1ll,vector<ll>(n,INF));

    for(ll i = 0; i < n; i++){
        dp[1ll<<i][i] = 1;
    }
    for(ll i = 1; i <= (1ll<<n); i++){
        for(ll j = 0; j < n; j++){
            if(dp[i][j] == INF){
                continue;
            }
            for(ll k = 0; k < n; k++){
                if (i&(1ll<<k)){
                    continue;
                }
                ll t = i|(1ll<<k);
                dp[t][k] = min(dp[t][k],dp[i][j]+dist[j][k]);
            }
        }
    }
    dbg(dp);

    dbg(arr);
    dbg(arr2);
    vector<ll> len(n,0);
    for(int i = 0; i < q; i++){
        if (arr2[i] == 1){
            len[arr[i]]++;
        }
    }

    dbg(len);
    ll ans = INF;
    ll t = (1ll<<n);
    for(ll i = 0; i < n; i++){
        ans = min(ans,dp[t-1][i]+len[i]);
    }
	cout << ans << nl;
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
// problem-url: https://codeforces.com/problemset/problem/2051/G
