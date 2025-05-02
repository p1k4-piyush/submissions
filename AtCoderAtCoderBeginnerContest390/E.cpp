//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing

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

const int MAX_N = 5e3+100;

void solve(){
	int n,x; cin >> n >> x;
    // int n1=0,n2=0,n3=0;
    vector<ll> n1(x+1,-INF),n2(x+1,-INF),n3(x+1,-INF);
	int v,a,c;
    n1[0] = 0; n2[0] = 0; n3[0] = 0;
	for(int i = 0; i < n; i++){
		cin >> v >> a >> c;
        if (v == 1){
            for(int j = x; j >= c; j--){
                n1[j] = max(n1[j],n1[j-c]+a);
            }
        }else if(v == 2){
            for(int j = x; j >= c; j--){
                n2[j] = max(n2[j],n2[j-c]+a);
            }
        }else if(v == 3){
            for(int j = x; j >= c; j--){
                n3[j] = max(n3[j],n3[j-c]+a);
            }
        }
	}
    ll t = 0;
    for(int i = 0; i < x+1; i++){
        t = max(n1[i],t);
        n1[i] = t;
    }
    t = 0;
    for(int i = 0; i < x+1; i++){
        t = max(n2[i],t);
        n2[i] = t;
    }

    t = 0;
    for(int i = 0; i < x+1; i++){
        t = max(n3[i],t);
        n3[i] = t;
    }

    dbg(n1);
    dbg(n2);
    dbg(n3);
    ll lo = 0, hi = INF;
    while(hi>lo){
        ll mid = lo + (hi-lo+1)/2;
        int t = lower_bound(n1.begin(),n1.end(),mid)-n1.begin();
        int t2 = lower_bound(n2.begin(),n2.end(),mid)-n2.begin();
        int t3 = lower_bound(n3.begin(),n3.end(),mid)-n3.begin();
        if (t+t2+t3 <= x){
            lo = mid;
        }else{
            hi = mid-1;
        }

    }

	cout << lo << nl;
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
// problem-url: https://atcoder.jp/contests/abc390/tasks/abc390_e
