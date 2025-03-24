//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I

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

const ll MAX_N = 3e5+100;
ll a[MAX_N];

void solve(){
	ll n,m; cin >> n >> m;
	ll kevin, count = 0;
    FOR(i,n){
    	cin >> a[i];
        if (i == 0){
            kevin = a[i];
        }else if (a[i] > kevin){
            count++;
        }
	}
    sort(a,a+n);
    ll t;
    vector<ll> arr;
    FOR(i,m){
        cin >> t;
        if (t > kevin){
            
            ll x = (a+n-lower_bound(a,a+n,t));
            if (x > 0){
                arr.push_back(x);
            }
        }
    }
    dbg(arr);
    sort(arr.begin(),arr.end(),greater<ll>());
    FOR(i,m){
        ll k = i+1;
        ll s = 0;
        ll tt = m%k;
        for(ll j = tt; j < (ll)(arr.size()); j += k){
            s += arr[j];
        }
        //cout << s << "e";
        cout << m/k + s << " ";
    }
	

    cout << nl;
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
// problem-url: https://codeforces.com/contest/2048/problem/D
