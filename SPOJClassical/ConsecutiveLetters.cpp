//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green

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
int n;
vector<pair<int,int>> arr;
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
    
    inline void debug(){
        dbg(p);
    }
};

void solve(int x){
    string ss;
    cin >> ss;
    n = ss.size();
    vector<char> s(n),s2(n);
    for(int i = 0; i < n; i++){
        s[i] = ss[i];
        s2[i] = ss[i];
    }
    int q; cin >> q;
	arr.assign(q,{0,0});

	for(int i = 0; i < q; i++){
		cin >> arr[i].first >> arr[i].second;
        arr[i].first--;
        if (arr[i].first){
            s2[arr[i].second] = '#';
        }
	}
    dsu d(n); 
    dsu d2(n);
    for(int i = 0; i < n-1; i++){
        if (s2[i]==s2[i+1] && s2[i] != '#'){
            d.unite(i,i+1);
        }
    }
    d.debug();
    for(int i = n-1; i > 0; i--){
        if (s2[i]==s2[i-1] && s2[i] != '#'){
            d2.unite(i,i-1);
        }
    }

    vector<int> ans;
    for(int i = q-1; i >= 0; i--){
        if (!arr[i].first){
            ans.push_back(d.get(arr[i].second)-d2.get(arr[i].second)+1);
        }else{
            s2[arr[i].second] = s[arr[i].second];
            if (arr[i].second < n-1 && s2[arr[i].second] == s2[arr[i].second+1]){
                d.unite(arr[i].second,arr[i].second+1);
            }
            if (arr[i].second > 0 && s2[arr[i].second] == s2[arr[i].second-1]){
                d.unite(arr[i].second-1,arr[i].second);
            }
            if (arr[i].second < n-1 && s2[arr[i].second] == s2[arr[i].second+1]){
                d2.unite(arr[i].second+1,arr[i].second);
            }
            if (arr[i].second > 0 && s2[arr[i].second] == s2[arr[i].second-1]){
                d2.unite(arr[i].second,arr[i].second-1);
            }

        }
        d.debug();
    }
    dbg(ans);
    reverse(all(ans));
    cout << "Case " << x << ":\n";
    for(auto i:ans){
        cout << i << nl;
    }
	return;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	cin >> t;
	for(int i = 1; i <= t; i++){
		solve(i);
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://www.spoj.com/problems/CONSEC/
