//  50 years is a long time
//  Holiday House sat quietly on that beach
//  Free of women with madness, their men and bad habits
//  And then it was bought by me

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
pair<ll,ll> arr[MAX_N];
ll arr2[MAX_N];
ll arr3[MAX_N];
ll ans[MAX_N];
void solve(){
	ll n,m,q; cin >> n >> m >> q;
	
	for(ll i = 0; i < n; i++){
		cin >> arr[i].first;
	}
    for(ll i = 0; i < n; i++){
		cin >> arr[i].second;
    }
    for(ll i = 0; i < m; i++){
		cin >> arr3[i];
        if(i == 0) continue;
        arr3[i] = arr3[i]+arr3[i-1];
	}
    for(ll i = 0; i < m+100ll; i++){
        ans[i] = INF;
    }

    sort(arr,arr+n,[](const pair<ll,ll> &a, const pair<ll,ll> &b){return a.second < b.second;});  

    for(ll i = 0; i < n; i++){
        if (i == 0) continue;
        arr[i].first += arr[i-1].first;
    }

    arr2[n] = INF;
    for(ll i = n-1; i >= 0; i--){
        arr2[i] = min(arr2[i+1],arr[i].second-arr[i].first);
    } 


    ll tt = 0;
    for(ll i = 0; i < n+1; i++){
        while(tt<m){
            if (arr3[tt]<=arr2[i]){
                ans[tt] = ((i>0)?arr[i-1].first:0ll)+arr3[tt];
                tt++; continue;
            }
            break;
        }
    }
    
    ll k;
    for(ll i = 0; i < q; i++){
        cin >> k;
        cout << upper_bound(ans,ans+m+100,k)-ans << " ";
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



// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2052/J
