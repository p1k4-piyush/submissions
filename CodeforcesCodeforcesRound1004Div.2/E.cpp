//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I


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
int n;
vector<int> arr;

void solve(){
	cin >> n;
	arr.assign(n,0);
    vector<vector<int>> v(n+1);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        if (arr[i]>n) continue;
        v[arr[i]].push_back(i);
	}

    int ans = 0;
    int l = n+5;
    for(int i = 0; i <= n; i++){
        if (v[i].size() == 0){
            break;
        }
        int c = 1;
        for(int j = 0; j < v[i].size()-1; j++){
            if (v[i][j] >= l){
                break;
            }
            ans++;
        }
        l = min(l,v[i][0]);
    }

    int t = v[0].size();
	cout << n-min(t,ans) << nl;
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
// problem-url: https://codeforces.com/contest/2067/problem/E

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2067/problem/E
