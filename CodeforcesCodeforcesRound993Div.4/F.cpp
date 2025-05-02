//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

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
int a[MAX_N];
int b[MAX_N];

void solve(){
	int n,m,q; cin >> n >> m >> q;
    int sum1 = 0,sum2=0;
    FOR(i,n){
    	cin >> a[i];
        sum1 += a[i];
	}
    FOR(i,m){
        cin >> b[i];
        sum2 += b[i];
    }
    sort(a,a+n);
    sort(b,b+m);
    FOR(j,q){
        int t; cin >> t;
        if (t == 0){
            if (binary_search(a,a+n,sum1)||binary_search(b,b+m,sum2)){
                cout << "YES\n"; continue;
            }else{
                cout << "NO\n"; continue;
            }
        }
        bool c = 0;
        int t2 = abs(t);
        int st2 = (int) sqrt(t2) +1;
        FOR(i,st2){
            if (i == 0){
                continue;
            }
            if (t2%i == 0){
                if (t > 0){
                    if ((binary_search(a,a+n,sum1-i) && binary_search(b,b+n,sum2-(t/i)))||(binary_search(a,a+n,sum1-(t/i)) && binary_search(b,b+n,sum2-i))||(binary_search(a,a+n,sum1+i)&&binary_search(b,b+m,sum2+(t/i)))||(binary_search(a,a+n,sum1+(t/i))&&binary_search(b,b+m,sum2+i))){
                        c = 1; break;
                    }
                }else{
                    if ((binary_search(a,a+n,sum1+i) && binary_search(b,b+n,sum2-(t2/i)))||(binary_search(a,a+n,sum1-(t2/i)) && binary_search(b,b+n,sum2+i))||(binary_search(a,a+n,sum1-i) && binary_search(b,b+n,sum2+(t2/i)))||(binary_search(a,a+n,sum1+(t2/i)) && binary_search(b,b+n,sum2-i))){
                        c = 1; break;
                    }

                }
            }
        }
        if (c){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }
    }

    cout << nl;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int t = 1;
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 4000
// problem-url: https://codeforces.com/contest/2044/problem/F
