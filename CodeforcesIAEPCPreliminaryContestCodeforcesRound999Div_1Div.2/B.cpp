//  We always walked a very thin line
//  You didn't even hear me out
//  You never gave a warning sign
//  All this time

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
int arr[MAX_N];

void solve(){
	int n; cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    sort(arr,arr+n);
    int x = -1,idx = -1;
    for(int i = n-1; i >= 1; i--){
        if (arr[i]==arr[i-1]){
            x = arr[i]; idx = i; break;
        }
    }
    if (x == -1){
        cout << "-1" << nl; return;
    }
    bool c = 0;
    for (int i = 0; i < n-1; i++){
        if (i == idx || i == idx-1){ 
            continue;
        }
        if (i == idx-2 && i+3 < n && arr[i+3]-arr[i] < 2*x){
            cout << arr[i] << " " << arr[i+1] << " " << arr[i+2] << " " << arr[i+3] << nl;
            return; 
        }
        if (i != idx-2 && arr[i+1]-arr[i] < 2*x){
            cout << arr[i] << " " << arr[i+1] << " " << x << " " << x << nl; 
            return;
        }
    }

	cout << "-1" << nl;
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
// problem-url: https://codeforces.com/contest/2061/problem/B
