//  And it took you five whole minutes
//  To pack us up and leave me with it
//  Holdin' all this love out here in the hall

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

void solve(){
	int n,m,q; cin >> n >> m >> q;
	
    FOR(i,q){
    	cin >> arr[i];
	}
    
    int s = 0, e = n+1;
    int lo = m,hi = m;
    FOR(i,q){
        if (arr[i] > s && s != 0){
            s++;
        }

        if (arr[i] < e && e != n+1){
            e--;
        }
        
        if (arr[i] == lo && arr[i] == hi){
            s = max(s,1);
            e = min(e,n);
            lo = -1; hi = -1;
        }
        
        if (lo == -1 && hi == -1){
            cout << min(n,s + (n+1-e)) << " ";
            continue;
        }
        
        if (arr[i]<lo){
            lo--;
        }else if (arr[i] == lo && arr[i] != hi){
            s = max(s,1);
            e = min(e,n);
        }

        if (arr[i]>hi && hi != -1){
            hi++;
        }else if (arr[i] == hi && arr[i] != lo){
            s = max(s,1);
            e = min(e,n);
        }

        if (arr[i]>lo && arr[i]<hi){
            s = max(s,1);
            e = min(e,n);
        }

        
        
        dbg(s); dbg(e); dbg(lo); dbg(hi);
        int ans = 0;
        if (s >= lo && e <= hi){
            ans = n;
        }else if (s >= lo){
            ans = hi + (n+1-e);
        }else if(e <= hi){
            ans = s + (n-lo+1);
        }else{
            ans = s + (hi-lo+1) + (n+1-e);
        }
        cout << ans << " ";
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
// problem-url: https://codeforces.com/contest/2051/problem/F
