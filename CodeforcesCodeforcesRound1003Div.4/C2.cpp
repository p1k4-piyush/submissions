//  I think I've seen this film before
//  And I didn't like the ending 
//  You're not my homeland anymore
//  So what am I defending now?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define int ll
const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,m;
vector<int> arr;
vector<int> arr2;

void solve(){
	cin >> n >> m;
	arr.assign(n,0);
    arr2.assign(m,0);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < m; i++){
		cin >> arr2[i];
	}
    sort(all(arr2));
    int prev = min(arr[0],arr2[0]-arr[0]);
    dbg(arr);
    dbg(arr2);
    for(int i = 1; i < n; i++){
        dbg(prev);
        auto t = lower_bound(all(arr2),arr[i]+prev);
        int tt;
        if (t == arr2.end()){
            tt = -INF;
        }else{
            tt = (*t)-arr[i];
        }
        dbg(tt);
        if (arr[i]>=prev && tt >= prev){
            prev = min(arr[i],tt);
        }else if(arr[i]>=prev){
            prev = arr[i];
        }else if(tt >= prev){
            prev = tt;
        }else{
            cout << "NO" << nl; return;
        }
        dbg(prev);
    }

	cout << "YES" <<  nl;
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
// problem-url: https://codeforces.com/contest/2065/problem/C1
