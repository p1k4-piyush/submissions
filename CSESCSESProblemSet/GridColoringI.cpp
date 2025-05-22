//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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

int n,m;

void solve(){
    cin >> n >> m;
    char t;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            if((i+j)&1){
                if(t == 'A'){
                    cout << "C";
                }else{
                    cout << "A";
                }
            }else{
                if(t == 'B'){
                    cout << "D";
                }else{
                    cout << "B";
                }
            }
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
// problem-url: https://cses.fi/problemset/task/3311
