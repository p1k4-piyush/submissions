//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

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

vector<vector<bool>> arr;
ll ans = 0;
vector<bool> col,diag1,diag2;

void f(int row){
    if(row == 8){
        ans++;
        return;
    }
    for(int co = 0; co < 8; co++){
        if(arr[row][co]||col[co]||diag1[row+co]||diag2[8+row-co]){
            continue;
        }
        col[co]=diag1[row+co]=diag2[8+row-co] = 1;
        f(row+1);
        col[co]=diag1[row+co]=diag2[8+row-co] = 0;
    }

}

void solve(){
    arr.assign(8,vector<bool>(8,0));
    char t;
    col.assign(8,0);
    diag1.assign(15,0);
    diag2.assign(15,0);

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cin >> t;
            if (t == '*'){
                arr[i][j] = 1;
            }
        }
    }
    
    f(0);
    
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
// problem-url: https://cses.fi/problemset/task/1624
