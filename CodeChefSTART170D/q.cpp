//  Sequin smile, black lipstick
//  Sensual politics
//  When you are young, they assume you know nothing


#include <bits/stdc++.h>
using namespace std;

typedef __int128 ll;

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
ll arr[MAX_N];
string s;
void print(__int128 x) {
    if (x < 0) {
        s +='-';
        x = -x;
    }
    if (x > 9) print(x / 10);
    s += (x % 10 + '0');
}
void solve(){
    long long n2; cin >> n2;
	ll n = n2;
    ll sum = 0;
    long long t;
	for(ll i = 0; i < n; i++){
		cin >> t;arr[i]=t;
	}
    
    sort(arr,arr+n);

    ll zero = 0;
    for(int i = 0; i < n; i++){
        sum = max(zero,sum+arr[i]-2*i-1);
    }
    s="";
    print(sum+(n*n));
	cout << s << nl;
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
// problem-url: https://www.codechef.com/START170D/problems/N3AL_
