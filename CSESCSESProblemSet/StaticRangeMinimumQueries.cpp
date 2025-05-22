//  They don't me all of my cages were mental
//  So I got wasted like all my potential
//  And my words shoot to kill when I'm mad
//  I have a lot of regret about that

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/


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



int n,q;
vector<int> arr;

void solve(){
    cin >> n >> q;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    auto fun = [&](int i,int j){
        return min(i,j);
    };

    SparseTable<int, decltype(fun)> sparse(arr,fun);

    int l,r;
    while(q--){
        cin >> l >> r;
        cout << sparse.get(l-1,r-1) << nl;
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
// problem-url: https://cses.fi/problemset/task/1647
