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

const int MAX_N = 1e6+100;
int arr[MAX_N];

void solve(){
	int n; cin >> n;
    bool c1=0,c2=0,c3=0;
    bool c4 = 0;
    FOR(i,n){
    	cin >> arr[i];
        if (c1 == 0 && arr[i]!=0){
            c1 = 1;
            continue;
        }
        if (c1 != 0 && c2 == 0 && arr[i]==0){
            c2 = 1; continue;
        }
        if (c1 != 0 && c2 != 0 && arr[i]!=0){
            c3 = 1; continue;
        }
	}
    if (!c1){
        cout << "0" << nl;
    }else if (!c3){
        cout << "1" << nl;
    }else{
        cout << "2" << nl;
    }
	

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



// time-limit: 1000
// problem-url: https://codeforces.com/contest/2049/problem/A
