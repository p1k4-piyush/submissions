//  Second, third, and hundreth chances
//  Balancin' on breaking branches
//  Those eyes add insult to injury

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
	map<int,int> mp;
    int l = -1;
    cin >> n;
    arr.assign(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    int ans = 0;
    int ansl = -1;
    for (int i = 0; i < n; i++){
        if(l == -1 && mp[arr[i]] == 1){
            l = i;
        }
        if (mp[arr[i]]!= 1){
            l = -1;
            continue;
        }
        if (i-l+1 > ans){
            ans = i-l+1;
            ansl = l;
        }
    }

    if (ans == 0){
        cout << "0\n"; return;
    }
    cout << ansl+1 << " " << ansl+ans << nl;

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



// time-limit: 1500
// problem-url: https://codeforces.com/contest/2064/problem/B
