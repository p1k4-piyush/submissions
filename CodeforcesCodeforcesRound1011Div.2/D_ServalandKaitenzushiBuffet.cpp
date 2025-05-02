//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I


#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif
const int MAX_N = 2e5+100;

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
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

class dsu {
 public:
  vector<int> p;
  int n;

  dsu(int _n) : n(_n) {
    p.resize(n);
    iota(p.begin(), p.end(), 0);
  }

  inline int get(int x) {
    return (x == p[x] ? x : (p[x] = get(p[x])));
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      p[x] = y;
      return true;
    }
    return false;
  }
};



int n,k;
vector<pair<int,int>> arr;

void solve(){
    cin >> n >> k;
    arr.assign(n,{0,0});
    
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i;
    }
    int a[n];
    for (int i = 0; i < n; i++){
        a[i] = 1;
    }

    build(a,1,0,n-1);

    dsu dsu1(n+1);
    sort(all(arr),greater<pair<int,int>>());
    ll ans = 0;

    for (auto &i : arr) {
        int t = i.second;
        int rem = sum(1,0,n-1,t,n-1);
        if (rem >= k+1) {
            ans  += i.first;  
            int t2 = dsu1.get(t);
            for (int j = 0; j < k+1; j++) {
                if(t2 == n){
                    cout << "e";break;
                }
                update(1,0,n-1,t2,0);
                dsu1.unite(t2, t2 + 1);
                t2 = dsu1.get(t2);
            }
        }
    }

    cout << ans << nl;
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
// problem-url: https://codeforces.com/contest/2085/problem/D

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2085/problem/D
