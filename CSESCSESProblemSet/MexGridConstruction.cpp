//  But there's robbers to the east, clowns to the west
//  I'd give you my sunshine, give you my best
//  But the rain is always gonna come if you're standing with me

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

int n;
vector<set<int>> row,col;

int mex(set<int> &arr1, set<int> &arr2){
    set<int> s;
    for(auto i:arr1){
        s.insert(i);
    }
    for(auto i:arr2){
        s.insert(i);
    }
    int cur = 0;
    while(s.count(cur)){
        cur++;
    }
    return cur;
}

void solve(){
    cin >> n;
    row.assign(n,set<int>());
    col.assign(n,set<int>());
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int t = mex(row[i],col[j]);
            cout << t << " ";
            row[i].insert(t);
            col[j].insert(t);
        }
        cout << nl;
    }
    
    
    cout << nl;
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
// problem-url: https://cses.fi/problemset/task/3419
