//  I think I've seen this film before
//  And I didn't like the ending 
//  You're not my homeland anymore
//  So what am I defending now?

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
    bool c = 1;
    int prev = arr[0];
    for(int i = 1; i < n; i++){
        dbg(prev);
        if (arr[i]>prev){
            if (!c){
                cout << "NO" << nl; return;
            }
            auto t = lower_bound(all(arr2),arr[i]+prev);
            if (t == arr2.end()){
                cout << "NO" << nl; return;
            }
            prev = (*t);
            c=!c;
        }
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
