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

const int MAX_N = 1e6+100;
int arr[MAX_N];

void solve(){
	int n; cin >> n;
    int z=0,o=0,t=0;	
    FOR(i,n){
    	cin >> arr[i];
        if (arr[i] == 0){
            z++;
        }else if (arr[i] == 1){
            o++;
        }else{
            t++;
        }
	}
    vector<int> v[3][3];

    FOR(i,n){
        if (i<z){
            if(arr[i] == 0) v[0][0].push_back(i);
            else if (arr[i] == 1) v[0][1].push_back(i);
            else v[0][2].push_back(i);
        }else if (i<o+z){
            if (arr[i] == 0) v[1][0].push_back(i);
            else if (arr[i] == 1) v[1][1].push_back(i);
            else v[1][2].push_back(i);
        }else{
            if (arr[i] == 0) v[2][0].push_back(i);
            else if (arr[i] == 1) v[2][1].push_back(i);
            else v[2][2].push_back(i);
        }
    }
	

    cout << nl;
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


