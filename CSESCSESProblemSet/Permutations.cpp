//  50 years is a long time
//  Holiday House sat quietly on that beach
//  Free of women with madness, their men and bad habits
//  And then it was bought by me

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

void solve(){
    cin >> n;
    if(n==1){
        cout << "1" << nl;
        return;
    }
    if (n < 4){
        cout << "NO SOLUTION" << nl;
        return;
    }
    if(n == 4){
        cout << "3 1 4 2" << nl;
        return;
    }
    for(int i = 1; i <= n; i+=2){
        cout << i << " ";
    }
    for(int i = 2; i <= n; i+=2){
        cout << i << " ";
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
// problem-url: https://cses.fi/problemset/task/1070
