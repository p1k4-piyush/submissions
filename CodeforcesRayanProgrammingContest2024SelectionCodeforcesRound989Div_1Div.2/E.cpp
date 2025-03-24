//  I knew I'd curse you for the longest time
//  Chasin' shadows in the grocery line
//  I knew you'd miss me once the thrill expired
//  And you'd be standin' in my front porch light

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
int f[11];

void solve(){
	int n,k; cin >> n >> k;
	int t = k;
    if (min(n,k) == 1){
        if (max(n,k) == 1){
            cout << "YES" << nl << "1" << nl; return;
        }
        cout << "NO" << nl; return;
    }
    if (n < 11 && (f[n]<k || f[n] == k+1)){
        cout << "NO" << nl; return;
    }
    if (!(n&1) && (k&1)){
        cout << "NO" << nl; return;
    }

    vector<vector<int>> ans, start;
    vector<int> per(n);
    for(int i = 0; i < n; i++) per[i] = i+1;
    if (k&1){
        vector<int> per1(n), per2(n);
        for(int i = 0; i < n; i++){
            per1[i] = (i&1)?n-i/2:(n+1)/2-i/2;
            per2[i] = (i&1)?n/2-i/2:n-i/2;
        }
        ans = start = {per,per1,per2};
        t-=3;
    }
    
    do{
        if (t == 0) break;
        vector<int> mirror(n);
        for(int i = 0; i < n; i++) mirror[i] = n+1-per[i];
        if (per < mirror){
            bool c = 1;
            for(auto &i: start) c &= !(i==per), c &= !(i==mirror);
            if (c){
                t-=2;
                ans.push_back(per); ans.push_back(mirror);
            }
        }
    }while(next_permutation(per.begin(),per.end()));

    cout << "YES" << nl;
    for(int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << nl;
    }
	return;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
    f[0] = 1;
    for(int i = 1; i < 11; i++) f[i] = i*f[i-1];
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2034/problem/E
