//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif


template <typename T>
class FenwickTree {
 public:
  vector<T> fenw;
  int n;
  int pw;

  FenwickTree() : n(0) {}
  FenwickTree(int n_) : n(n_) {
    fenw.resize(n);
    pw = bit_floor(unsigned(n));
  }

  void Modify(int x, T v) {
    assert(0 <= x && x <= n);
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  T Query(int x) {
    assert(0 <= x && x <= n);
    T v{};
    while (x > 0) {
      v += fenw[x - 1];
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
        nv += fenw[at + len - 1];
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


void evermore(){
    int n,q;
    string s;
    cin >> s;
    n = s.size();
    vector<FenwickTree<int>>arr(26,n);

    for(int i = 0; i < n; i++){
        arr[s[i]-'a'].Modify(i,1);
    }

    cin >> q;
    int t;
    int l,r;
    char tt;
    while(q--){
        cin >> t;
        if(t == 1){
            cin >> l >> tt;
            l--;
            arr[s[l]-'a'].Modify(l,-1);
            s[l] = tt;
            arr[s[l]-'a'].Modify(l,1);
        }else{
            cin >> l >> r;
            l--;
            int ans = 0;
            for(auto &i:arr){
                if(i.Query(r)>i.Query(l)){
                    ans++;
                }
            }
            cout << ans << nl;
        }
    }
    
    
    cout << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    while(number_of_albums--){
        evermore();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/1234/D
