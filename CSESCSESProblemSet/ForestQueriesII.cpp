//  And it took you five whole minutes
//  To pack us up and leave me with it
//  Holdin' all this love out here in the hall

#include <bits/stdc++.h>
using namespace std;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

template <typename T>
class FenwickTree2D {
 public:
  vector<vector<T>> fenw;
  int n, m;

  FenwickTree2D() : n(0), m(0) {}
  FenwickTree2D(int n_, int m_) : n(n_), m(m_) {
    fenw.resize(n);
    for (int i = 0; i < n; i++) {
      fenw[i].resize(m);
    }
  }

  void Modify(int i, int j, T v) {
    assert(0 <= i && i < n && 0 <= j && j < m);
    int x = i;
    while (x < n) {
      int y = j;
      while (y < m) {
        fenw[x][y] += v;
        y |= y + 1;
      }
      x |= x + 1;
    }
  }

  T Query(int i, int j) {
    assert(0 <= i && i <= n && 0 <= j && j <= m);
    T v{};
    int x = i;
    while (x > 0) {
      int y = j;
      while (y > 0) {
        v += fenw[x - 1][y - 1];
        y &= y - 1;
      }
      x &= x - 1;
    }
    return v;
  }
    T Query(int i1, int j1,int i2, int j2){
        return Query(i2+1,j2+1)+Query(i1,j1)-Query(i1,j2+1)-Query(i2+1,j1);
    }
};
int n,q;
vector<vector<int>> arr;

void solve(){
    cin >> n >> q;
    char t;

    FenwickTree2D<ll> fenw(n,n);
    arr.assign(n+1,vector<int>(n+1,0));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> t;
            if(t == '*'){
                arr[i][j] = 1;
                fenw.Modify(i,j,1);
            }
        }
    }

    int x1,x2,y1,y2;
    while(q--){
        cin >> t;
        if (t =='1'){
            cin >> y1 >> x1;
            y1--;x1--;
            int old = arr[y1][x1];
            int new1 = abs(old-1);
            arr[y1][x1] = new1;
            fenw.Modify(y1,x1,new1-old);
        }else{
            cin >> y1 >> x1 >> y2 >> x2;
            x1--;y1--;
            x2--;y2--;
            ll ans = fenw.Query(y1,x1,y2,x2);
            cout << ans << nl;
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
// problem-url: https://cses.fi/problemset/task/1739
