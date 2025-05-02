//  'Cause I knew you
//  Steppin' on the last train
//  Marked me like a bloodstain, I

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
int arr2[MAX_N];

int t[4*MAX_N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = __gcd(t[v*2],t[v*2+1]);
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return __gcd(sum(v*2, tl, tm, l, min(r, tm)),sum(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void solve(){
	int n,q; cin >> n >> q;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        if (i == 0) continue;
        arr2[i-1] = abs(arr[i]-arr[i-1]);
	}
    if(n>=2) build(arr2,1,0,n-2);
    int t1,t2;
    for(int i = 0; i < q; i++){
        cin >> t1 >> t2;
        cout << sum(1,0,n-2,t1-1,t2-2) << " ";
    }
    cout << nl;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int t2 = 1;
	cin >> t2;
	while(t2--){
		solve();
	}
	return 0;
}



// time-limit: 5000
// problem-url: https://codeforces.com/contest/2050/problem/F
