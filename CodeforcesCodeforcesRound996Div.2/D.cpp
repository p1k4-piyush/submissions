//  I knew you
//  Tried to change the ending
//  Peter losing Wendy, I

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
	int n,k,l; cin >> n >> k >> l;
    k <<= 1; l <<= 1;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i]; arr[i] <<= 1;
	}

    int ans = arr[0], x = k;

    for(int i = 1; i < n && x < l; i++){
        if (arr[i] + ans < x){
            x = arr[i] + ans + k;
        }else if (arr[i] - ans > x){
            int tt = (arr[i]-ans-x)/2;
            ans += tt; x += tt+k;
        }else{
            x += k;
        }
    }

    if (x < l){
        ans += l-x;
    }

	cout << ans << nl;
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2055/problem/D
