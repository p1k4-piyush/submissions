
//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

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

const int MAX_N = 2e5+100;
int arr[MAX_N];

void solve(){
	int n; cin >> n;
    char t;
    vector<string> s = {"RGB","RBG","GRB","GBR","BRG","BGR"};
    vector<int> ans (6,0);
	for(int i = 0; i < n; i++){
		cin >> t;
        for(int j = 0; j < 6; j++){
            if (t != s[j][i%3]){
                ans[j]++;
            }
        }
	}
    

	cout << *min_element(ans.begin(),ans.end()) << nl;
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
// problem-url: https://www.codechef.com/START171B/problems/WHITEWALL
