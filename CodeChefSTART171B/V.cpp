//  A friend to all is a friend to none
//  Chase two girls, lose the one
//  When you are young, they assume you know nothin'

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

const int MAX_N = 3e5+100;
int arr[MAX_N];
int ans[MAX_N];

void solve(){
	int n,p; cin >> n >> p;
	vector<int> v;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        if(arr[i] == 0){
            v.push_back(i);
        }
        ans[i] = INT_MAX;
	}
    for(int i = 0; i < v.size(); i++){
        ans[v[i]]=0;
    }
    for(int i = 0; i < v.size();i++){
        int l; 
        int r;
        if (i == 0){
            l = -1;
        }else{
            l = v[i-1];
        }
        if(i == v.size()-1){
            r=n;
        }else{
            r = v[i+1];
        }
        for(int j = v[i]-1; j > l; j--){
            ans[j] = min(ans[j],max((arr[j]+p-1)/p,ans[j+1]));
        }
        for(int j = v[i]+1; j < r; j++){
            ans[j] = min(ans[j],max((arr[j]+p-1)/p,ans[j-1]));
        }
    }
     
    for(int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }


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



// time-limit: 1000
// problem-url: https://www.codechef.com/START171B/problems/VOLCANO
