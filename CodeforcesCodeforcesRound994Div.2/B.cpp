//  I guess you never know, never know
//  And if you wanted me, you really should have showed
//  And if you never bleed, you're never gonna grow
//  And it's alright now

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

const int MAX_N = 500+100;
char arr[MAX_N];

void solve(){
	int n; cin >> n;
	vector<int> p,s;
    FOR(i,n){
    	cin >> arr[i];
        if (arr[i]== 'p'){
            p.push_back(i);
        }else if (arr[i] == 's'){
            s.push_back(i);
        }
	}
    if (s.size() == 0 || p.size() == 0){
        cout << "YES" << nl; return;
    }
    if (s.size() == 1){
        if (s[0] == 0){
            cout << "YES" << nl; return;
        }
    }
    if (p.size() == 1){
        if (p[0] == n-1){
            cout << "YES" << nl; return;
        }
    }

    cout << "NO" << nl;
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



// time-limit: 1000
// problem-url: https://codeforces.com/contest/2049/problem/B
