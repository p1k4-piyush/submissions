//  We always walked a very thin line
//  You didn't even hear me out
//  You never gave a warning sign
//  All this time

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
int n;

void solve(){
	cin >> n;
    char t;
    vector<int> z,o;
	for(int i = 0; i < n; i++){
		cin >> t;
        if (t == '0'){
            z.push_back(i);
        }else{
            o.push_back(i);
        }
	}
    int oo = o.size();
    int ans = 0;
    int tt = oo/2;
    for(int  i = 0; i < oo; i++){
        ans += abs(o[i]-o[tt]-(i-tt));
    }
	cout << ans << nl;
	return;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc393/tasks/abc393_d
