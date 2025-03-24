//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet


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
int n;
vector<int> arr;

vector<int> lp(MAX_N+1);
vector<int> pr;

void solve(){
	cin >> n;
	arr.assign(n,0);
    map<ll,ll> mp;
    ll tt = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        if (lp[arr[i]]==arr[i]){
            mp[arr[i]]++;
            tt++;
            dbg(arr[i]);
        }
	}
    ll ans = 0;
    for(auto i:mp){
        ans += (i.second)*(tt-i.second);
    }
    ans /= 2;
    map<ll,ll> mp2;
    for(int i = 0; i < n; i++){
        ll t = lp[arr[i]];
        ll t2 = lp[arr[i]/t];
        if(t == arr[i]){
            continue;
        }
        if (arr[i]/t == t2){
            mp2[arr[i]]++;
            dbg(t);
            dbg(t2);
            if(arr[i]/t == t){
                ans += mp[t];
                ans += mp2[arr[i]];
            }else{
                ans += mp[t];
                ans += mp[arr[i]/t];
                ans += mp2[arr[i]];
            }
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
    
    for (int i=2; i <= MAX_N; ++i) {
    if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= MAX_N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
    }
}

	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2065/problem/G

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2065/problem/G
