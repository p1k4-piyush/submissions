//  The wedding was charming, if a little gauche
//  There's only so far as new money goes
//  They picked out a home and called it "Holiday House"

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

vector<char> lucky;

void evermore(){
    int n,m,l,r,d;
    cin >> n >> m;
    vector<int> check= {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777, 4444, 4447, 4474, 4477, 4744, 4747, 4774, 4777, 7444, 7447, 7474, 7477, 7744, 7747, 7774, 7777,44444};
    lucky.assign(1e4+100,0);
    l = 0;
    for(int i = 0;i < 1e4+100; i++){
        if(i > check[l]){
            l++;
        }
        if(i == check[l]){
            lucky[i]=1;
        }
    }
    
    FenwickTree<int> fenw(n);
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(lucky[arr[i]]){
            fenw.Modify(i,1);
        }
    }
    string s;
    while(m--){
        cin >> s;
        if (s == "count"){
            cin >> l >> r;
            l--;
            cout << fenw.Query(r)-fenw.Query(l) << nl;
        }else{
            cin >> l >> r >> d;
            l--;
            for(int i = l; i<r;i++){
                if(lucky[arr[i]]){
                    fenw.Modify(i,-1);
                }
                arr[i]+=d;
                if(lucky[arr[i]]){
                    fenw.Modify(i,1);
                }
            }
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


// time-limit: 4000
// problem-url: https://codeforces.com/contest/121/problem/E
