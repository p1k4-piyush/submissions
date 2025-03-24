//  I can see you starin', honey
//  Like he's just your understudy
//  Like you'd get your knuckles bloody for me


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,q;
vector<int> l;
vector<int> r;
vector<int> c;
vector<int> ans;

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

void solve(){
	cin >> n >> q;
	l.assign(q,0);
    r.assign(q,0);
    c.assign(q,0);
    ans.assign(n,0);
    dsu d(n+1);
	for(int i = 0; i < q; i++){
		cin >> l[i] >> r[i] >> c[i];
        l[i]--;
        r[i]--;
	}

    for(int i = q-1; i >= 0; i--){
        for(int t = d.get(l[i]); t<=r[i]; t = d.get(t)){
            ans[t] = c[i];
            d.unite(t,t+1);
        }
    }

    for(auto i:ans){
        cout << i << nl;
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



// time-limit: 2000
// problem-url: https://www.spoj.com/problems/CLFLARR/
