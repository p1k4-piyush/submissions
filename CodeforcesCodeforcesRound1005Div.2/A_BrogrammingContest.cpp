//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing

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
	string s; cin >> s;
    char prev = '0';
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        if (prev == s[i]){
            continue;
        }
        prev = s[i];
        ans++;
    }

	cout << ans << nl;
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
// problem-url: https://codeforces.com/contest/2064/problem/A
