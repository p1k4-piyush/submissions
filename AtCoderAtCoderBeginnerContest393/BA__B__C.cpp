//  Bill was the heir to Standard Oil name and money
//  And the town said, "How did a middle-class divorcée do it?

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
    string s; cin >> s;
	n = s.size();
    int ans = 0;
	for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int k = 2*j -i;
            if (k >= n) continue;
            if (s[i] == 'A' && s[j] == 'B' && s[k] == 'C'){
                ans++;
            }
        }
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
// problem-url: https://atcoder.jp/contests/abc393/tasks/abc393_b
