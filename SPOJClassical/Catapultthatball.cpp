//  Their parties were tasteful if a little loud
//  The doctor had told him to settle down
//  It must have been her faunt his heart gave out

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

const int MAX_N = 2e5+100;
ll n;
vector<ll> arr;

template <typename T, typename F>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};

void solve(){
	cin >> n;
    ll q; cin >> q;
	arr.assign(n,0);

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
     
    SparseTable<ll,function<ll(ll,ll)>> st(arr,[](ll i, ll j){ return max(i,j); });
    ll l,r;
    ll ans = 0;
    for(ll i = 0; i < q; i++){
        cin >> l >> r;
        l--; r--;
        if (l>r){
            ans += (arr[r]>=st.get(r,l-1))?1:0;
            continue;
        }
        if (l == r){
            ans++; continue;
        }
        ans += (arr[l]>=st.get(l,r-1))?1:0;
    }
    

	cout << ans << nl;
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



// time-limit: 1000
// problem-url: https://www.spoj.com/problems/THRBL/
