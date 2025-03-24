//  Bill was the heir to Standard Oil name and money
//  And the town said, "How did a middle-class divorcée do it?

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define int ll
const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,k;
vector<int> arr;
vector<int> pre;
void solve(){
	cin >> n >> k;
	arr.assign(n,0);
    pre.assign(n,0);
    ll t = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        t+= arr[i];
	}

    sort(all(arr));
    pre[0] = arr[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1]+arr[i];
    }
    int lo = 0, hi = 1e10 +100;
    while(hi > lo){
        int mid = (lo+hi)/2;
        bool c = 0;
        for(int i = 0; i <= min(n-1,mid); i++){
            int fi = arr[0] - mid+i;
            int sum = fi*(i+1) + pre[n-i-1] - arr[0];
            if(sum <= k){
                c = 1; break;
            }
        }
        if (c){
            hi = mid;
        }else{
            lo = mid+1;
        }

    }

	cout << hi << nl;
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
// problem-url: https://codeforces.com/contest/1622/problem/C
