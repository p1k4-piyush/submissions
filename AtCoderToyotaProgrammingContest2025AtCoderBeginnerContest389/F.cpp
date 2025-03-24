//  We gather here, we line up, weepin' in a sunlit room
//  And if I'm on fire, you'll be made of ashes tooi

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

const int MAX_N = 5e5+100;
int arr[MAX_N];
int t[4*MAX_N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm))
           + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = t[v]+new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void solve(){
	int n; cin >> n;
    int l,r;
    build(t,1,0,MAX_N-1);
	for(int i = 0; i < n; i++){
		cin >> l >> r;
	    int lo = 0, hi = l;
        while(hi > lo){
            int mid = (lo+hi)/2;
            if (mid + sum(1,0,MAX_N-1,0,mid-1) >= l){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        int tt = lo;
        lo = 0; hi = r+1;
        while(hi > lo){
            int mid = (lo+hi)/2;
            if (mid + sum(1,0,MAX_N-1,0,mid-1) > r){
                hi = mid;
            }else{
                lo = mid+1;
            }
        }
        if (tt+sum(1,0,MAX_N-1,0,tt-1) >= l)    update(1,0,MAX_N-1,tt-1,1); 
        if (lo+sum(1,0,MAX_N-1,0,lo-1) > r)     update(1,0,MAX_N-1,lo-1,-1);

    }
    
    cin >> n;
    while(n--){
        cin >> l;
        cout << sum(1,0,MAX_N-1,0,l-1) + l << nl;
    }

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



// time-limit: 2500
// problem-url: https://atcoder.jp/contests/abc389/tasks/abc389_f
