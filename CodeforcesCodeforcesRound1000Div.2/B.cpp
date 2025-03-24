//  And they said
//  "There goes the last great American dynasty
//  Who knows, if she never showed up, what could've been
//  There goes the maddest woman this town has ever seen
//  She had a marvelous time ruining everything"

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 1e5+100;
int arr[MAX_N];
int larr[MAX_N];
int rarr[MAX_N];

void solve(){
	int n,l,r; cin >> n >> l >> r;
	
	for(int i = 0; i < l-1; i++){
		cin >> larr[i];
	}
    
    for(int i = 0; i < r-l+1; i++){
        cin >> arr[i];
    }

    for(int i = 0; i < n-r; i++){
        cin >> rarr[i];
    }

    sort(larr,larr+l-1);
    sort(arr,arr+r-l+1);
    sort(rarr,rarr+n-r);

    int i = 0, j = 0, k = 0;
    int sum = 0;
    int ans = 0;
    for(int tt = 0; tt < r-l+1; tt++){
        if (i >= l-1){
            sum += arr[j]; j++; continue;
        }
        if (arr[j]<=larr[i]){
            sum += arr[j]; j++;
        }else{
            sum += larr[i]; i++;
        }        
    }
    ans = sum;
    j = 0;
    sum = 0;
    for(int tt = 0; tt < r-l+1; tt++){
        if (k >= n-r){
            sum += arr[j]; j++; continue;
        }
        if (arr[j]<=rarr[k]){
            sum += arr[j]; j++;
        }else{
            sum += rarr[k]; k++;
        }        
    }

	cout << min(ans,sum) << nl;
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



// time-limit: 1500
// problem-url: https://codeforces.com/contest/2063/problem/B
