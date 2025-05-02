//  But there's robbers to the east, clowns to the west
//  I'd give you my sunshine, give you my best
//  But the rain is always gonna come if you're standing with me

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/

// #include<bits/extc++.h>
#include <ext/pb_ds/assoc_container.hpp>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;

template <typename T>
class DynamicFenwickTree {
 public:
  HashMap<int, T> fenw;
  int n;
  int pw;

  DynamicFenwickTree() : n(0) {}
  DynamicFenwickTree(int n_) : n(n_) {
    pw = bit_floor(unsigned(n));
  }

  void Modify(int x, T v) {
    assert(0 <= x && x < n);
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  T Query(int x) {
    assert(0 <= x && x <= n);
    T v{};
    while (x > 0) {
      auto it = fenw.find(x - 1);
      if (it != fenw.end()) {
        v += it->second;
      }
      x &= x - 1;
    }
    return v;
  }

  // Returns the length of the longest prefix with sum <= c
  int MaxPrefix(T c) {
    T v{};
    int at = 0;
    for (int len = pw; len > 0; len >>= 1) {
      if (at + len <= n) {
        auto nv = v;
        auto it = fenw.find(at + len - 1);
        if (it != fenw.end()) {
          nv += it->second;
        }
        if (!(c < nv)) {
          v = nv;
          at += len;
        }
      }
    }
    assert(0 <= at && at <= n);
    return at;
  }
};


int n,q;
vector<int> arr;
vector<pair<bool,pair<int,int>>> queries;

void solve(){
    cin >> n >> q;
    arr.assign(n,0);
    queries.assign(q,{0,{0,0}});
    vector<int> v;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        v.push_back(arr[i]);
    }
    
    char t;

    for(int i = 0; i < q; i++){
        cin >> t >> queries[i].second.first >> queries[i].second.second;
        if(t == '!'){
            queries[i].first = 1;
            v.push_back(queries[i].second.second);
        }else{
            v.push_back(queries[i].second.first);
            v.push_back(queries[i].second.second);
        }
    }

    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    
    DynamicFenwickTree<int> fen(v.size());

    for(auto i:arr){
        int j = lower_bound(v.begin(),v.end(),i)-v.begin();
        fen.Modify(j,1);
    }

    for(auto i:queries){
        if(i.first){
            int j = lower_bound(v.begin(),v.end(),arr[i.second.first-1])-v.begin();
            fen.Modify(j,-1);
            arr[i.second.first-1] = i.second.second;
            j = lower_bound(v.begin(),v.end(),arr[i.second.first-1])-v.begin();
            fen.Modify(j,1);
        }else{
            int l = lower_bound(v.begin(),v.end(),i.second.first)-v.begin();
            int r = lower_bound(v.begin(),v.end(),i.second.second)-v.begin()+1;
            cout << fen.Query(r)-fen.Query(l) << nl;
        }
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1144
