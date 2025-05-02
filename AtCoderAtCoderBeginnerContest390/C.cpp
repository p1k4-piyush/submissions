//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I

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

const int MAX_N = 1000+100;
char arr[MAX_N][MAX_N];

void solve(){
	int n,m; cin >> n >> m;
    
    int top = -1, bottom = -1,l=-1,r=-1;
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if (arr[i][j]=='#'){
                if (top == -1){
                    top = i;
                }
                bottom = i;
                if(l == -1){
                    l = j;
                }
                l = min(l,j);
                r = max(r,j);
            }
        }
	}
    bool c = 1;
    for(int i = top; i <= bottom; i++){
        for(int j = l; j <= r; j++){
            if(arr[i][j] == '.'){
                cout << "No" << nl; return;
            }
        }
    }
    
    

	cout << "Yes" << nl;
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
// problem-url: https://atcoder.jp/contests/abc390/tasks/abc390_c
