//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green

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

void solve(){
	cin >> n;
	int t;
    map<int,int> mp;
    bool c = 1;

	for(int i = 0; i < n; i++){
		cin >> t;
        if (!c){
            continue;
        }
        if (mp.find(t)!=mp.end()){
            cout << "1\n" << t << nl;
            c = 0;
        }else{
            mp[t] = 1;
        }
	}

    if(c){
        cout << "-1" << nl;
    }
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
// problem-url: https://www.codechef.com/START173B/problems/COOLSUB
