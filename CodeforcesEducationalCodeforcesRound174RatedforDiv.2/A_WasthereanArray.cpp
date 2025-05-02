//  And when I felt like I was an old cardigan
//  Under someone's bed
//  You put me on and said I was your favorite

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

	for(int i = 0; i < n-2; i++){
		cin >> arr[i];
	}
    bool ans = 1;
    for(int i = 1; i < n-3; i++){
        if (arr[i] == 0 && arr[i-1] == 1 && arr[i+1] == 1){
            ans = 0; break;
        }
    }


	cout << (ans?"YES":"NO") << nl;
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
// problem-url: https://codeforces.com/contest/2069/problem/A
