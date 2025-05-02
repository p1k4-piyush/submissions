//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// #define int ll
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

void solve(){
	int n; cin >> n;
	vector<vector<int>> arr(n,vector<int>(n));

	for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
		    cin >> arr[i][j];
        }
	}

    dbg(arr);
    vector<int> ans(n+1,0);
    for(int i = 0; i < n; i++){
        int c = 0;
        for(int j = n-1; j >= 0; j--){
            if (arr[i][j]==1){
                c++;
            }else{
                break;
            }
        }
        ans[c]++;
    }
    for(int i = n-1; i>=0; i--){
        ans[i] += ans[i+1];
    }
    dbg(ans);
    int lo = 1, hi = n;
    while(hi > lo){
        int mid = (hi+lo+1)/2;
        bool c = 1;
        for(int i = mid-1; i > 0; i--){
            if (ans[i]<mid-i){
                c = 0; break;
            }
        }
        if (c){
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
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2059/problem/C
