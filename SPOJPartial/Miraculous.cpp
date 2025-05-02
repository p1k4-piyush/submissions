//  I didn't have it in myself to go with grace
//  And so the battleships will sink beneath the waves
//  You had to kill me, but it killed you just the same


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
int h,b,e;
vector<pair<int,int>> arr;
vector<int> ans;

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

//SparseTable<int,function<int(int,int)>> st(arr, [](int i, int j){ return min(i,j); });

void solve(int n){
	cin >> h >> b >> e;
	arr.assign(n,{0,0});
    ans.assign(n,0);

	for(int i = 0; i < n; i++){
		cin >> arr[i].first;
        arr[i].second = -i;
	}
    SparseTable<pair<int,int>,function<pair<int,int>(pair<int,int>,pair<int,int>)>> st(arr,[](pair<int,int> i, pair<int,int> j){    return min(i,j);    });

    for(int i = 0; i < n; i++){
        pair<int,int> t = st.get(max(0,i-h),i);
        ans[-t.second]++;
    }
    for(int i = b-1; i < e; i++){
        cout << ans[i] << " ";
    }

	cout << nl;
	return;
}


signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t = 1;
	while(cin >> t){
		solve(t);
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://www.spoj.com/problems/TNVFC1M/


// time-limit: 2000
// problem-url: https://www.spoj.com/problems/TNVFC1M/
