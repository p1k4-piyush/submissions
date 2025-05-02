//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet

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

struct CUS{
    int min1, min2, max1, max2, ans1, ans2;
    CUS() : min1(INT_MAX), min2(INT_MAX), max1(INT_MIN), max2(INT_MIN), ans1(0), ans2(0) {}

    CUS(pair<int,int> x) : min1(x.first), min2(x.second), max1(x.first), max2(x.second), ans1(0), ans2(0) {}
};

CUS operator+(const CUS &a, const CUS &b){
    CUS res;
    res.min1 = min(a.min1,b.min1);
    res.max1 = max(a.max1,b.max1);
    res.min2 = min(a.min2,b.min2);
    res.max2 = max(a.max2,b.max2);
    res.ans1 = max(b.max1 - a.min1, max(a.ans1,b.ans1));
    res.ans2 = max(a.max2 - b.min2, max(a.ans2,b.ans2));
    return res;
}

const int MAX_N = 2e5+100;
int arr[MAX_N];
int a[MAX_N];
int b[MAX_N];
CUS t[4*MAX_N];

void build(int a[],int b[], int v, int tl, int tr){
    if (tl == tr){
        t[v] = CUS({a[tl],b[tl]});
    }else{
        int tm = (tl+tr)/2;
        build(a,b,v*2,tl,tm);
        build(a,b,v*2+1,tm+1,tr);
        t[v] = t[v*2]+t[v*2+1];
    }
}

CUS sum(int v, int tl, int tr, int l , int r){
    if (l > r){
        CUS zero;
        return zero;
    }
    if (l == tl && r == tr){
        return t[v];
    }

    int tm = (tl+tr)/2;
    return sum(v*2,tl,tm,l,min(r,tm)) + sum(v*2+1,tm+1,tr,max(l,tm+1),r);
}

void update(int v, int tl, int tr, int pos, pair<int,int> new_val){
    if (tl == tr){
        t[v] = CUS(new_val);
    }else{
        int tm = (tl+tr)/2;
        if (pos<=tm){
            update(v*2,tl,tm,pos,new_val);
        }else{
            update(v*2+1,tm+1,tr,pos,new_val);
        }
        t[v] = t[v*2]+t[v*2+1];
    }
}

void solve(){
	int n,q; cin >> n >> q;
	
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
        a[i] = arr[i] - i;
        b[i] = arr[i] -n + i;
	}
    
    build(a,b,1,0,n-1);

    // for(int i = 0; i < n*4; i++){
    //     cout << t[i].first << " " << t[i].second << nl;
    // }

    CUS p = sum(1,0,n-1,0,n-1);
    cout << max(p.ans1,p.ans2) << nl;
    int tt,ttt;
    for(int i = 0; i < q; i++){
        cin >> tt >> ttt;
        update(1,0,n-1,tt-1,{ttt-tt+1,ttt-n+tt-1});
        p = sum(1,0,n-1,0,n-1);
        cout << max(p.ans1,p.ans2) << nl;

    }

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
// problem-url: https://codeforces.com/contest/2057/problem/D
