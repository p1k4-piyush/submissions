//  And you can aim for my heart, go for blood
//  And you would still miss me in your bones
//  And I still talk to you
//  And when you can't sleep at night (you hear my stolen lullabies)


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
ll n;
string s;
vector<ll> c;
vector<ll> d;

void solve(){
	cin >> s;
	n = s.size();
    ll t = -1;
    for(ll i = 0; i < n/2; i++){
        if(s[i] != s[n-1-i]){
            t = i; break;
        }
    }
    if (t == -1){
        cout << "0" << nl; return;
    }
       
    ll lo = 0,hi = n,mid;
    while(hi > lo){
        mid = (hi+lo)/2;
        c.assign(26,0);
        for (ll i = t; i < t+mid; i++){
            c[s[i]-'a']++;
        }
        d.assign(26,0);
        dbg(t+mid,n-t-mid-1);
        for(ll i = max(t+mid,n-t-mid); i < n-t; i++){
            d[s[i]-'a']++;
        }
        dbg(c);
        dbg(d);

        bool c2 = 1;
        for(ll i = 0; i < 26; i++){
            if (d[i]>c[i]){
                c2 = 0; break;
            }
        }
        for (ll i = t+mid; i < n-t-mid; i++){
            if (s[i] != s[n-1-i]){
                c2 = 0; break;
            }
        }

        if (!c2){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }
    
    reverse(all(s));
    lo = 0;
    while(hi > lo){
        mid = (hi+lo)/2;
        c.assign(26,0);
        for (ll i = t; i < t+mid; i++){
            c[s[i]-'a']++;
        }
        d.assign(26,0);
        dbg(t+mid,n-t-mid-1);
        for(ll i = max(t+mid,n-t-mid); i < n-t; i++){
            d[s[i]-'a']++;
        }
        dbg(c);
        dbg(d);

        bool c2 = 1;
        for(ll i = 0; i < 26; i++){
            if (d[i]>c[i]){
                c2 = 0; break;
            }
        }
        for (ll i = t+mid; i < n-t-mid; i++){
            if (s[i] != s[n-1-i]){
                c2 = 0; break;
            }
        }

        if (!c2){
            lo = mid+1;
        }else{
            hi = mid;
        }
    }


	cout << hi << nl;
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2069/problem/D
