//  But we were something, don't you think so?
//  Roaring 20s, tossing pennies in the pool
//  And if my wishes came true
//  It would've been you


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
int arr[int(1e5+1)];
void solve(){
	int n; cin >> n;
	map<int,int> mp;
    FOR(i,n){
    	cin >> arr[i];
        mp[arr[i]]++;
	}
	FOR(i,n){
        if (arr[i] == mp.begin()->first){
            cout << arr[i] << " ";
            mp.begin()->second = mp.begin()->second-1;
            if (mp.begin()->second==0){
                mp.erase(mp.begin()->first);
            }
        }else{
            mp[arr[i]]--;
            mp[arr[i]+1]++;
            if (mp[arr[i]] == 0){
                mp.erase(arr[i]);
            }
        }
    }
    while(!(mp.empty())){
        cout << mp.begin()->first << " ";
        mp.begin()->second--;
        if (mp.begin()->second == 0){
            mp.erase(mp.begin()->first);
        }
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
// problem-url: https://codeforces.com/contest/2047/problem/D
