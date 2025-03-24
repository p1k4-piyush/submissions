//  I guess you never know, never know
//  And if you wanted me, you really should have showed
//  And if you never bleed, you're never gonna grow
//  And it's alright now


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

void solve(){
	int n,m; cin >> n >> m;
    vector<vector<pair<bool,int>>> arr(n,vector<pair<bool,int>>(m));
    char t;
	
	for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            arr[i][j] = {(t=='.'),-1};
        }
	}
    arr[n-1][m-1] = {1,0};
    for(int i = n-1; i >= 0; i--){
        for(int j = m-1; j >= 0; j--){
            if(arr[i][j].first){
                if(i!=n-1 && arr[i+1][j].first){
                    if (arr[i][j].second == -1){
                        arr[i][j].second = arr[i+1][j].second+1;
                    }
                    arr[i][j].second = min(arr[i][j].second,arr[i+1][j].second+1);
                }
                if(j!=m-1 && arr[i][j+1].first){
                    if (arr[i][j].second == -1){
                        arr[i][j].second = arr[i][j+1].second+1;
                    }
                    arr[i][j].second = min(arr[i][j].second,arr[i][j+1].second+1);
                }
            }
        }
    }
    cout << arr[0][0].second;

	cout << nl;
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



// time-limit: 3000


// time-limit: 3000
