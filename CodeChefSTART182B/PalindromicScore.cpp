//  You know I didn't want to have to haunt you
//  But what a ghostly scene
//  You wear the same jewels that I gave you
//  As you bury me

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

int a,b,c;

void solve(){
    cin >> a >> b >> c;
    
    if(a > c){
        swap(a,c);
    }
    if(b > c){
        swap(b,c);
    }

    if((a%2 == 1)&&(b%2 == 1)){
        a--;
    }

    cout << a + b << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 1000
// problem-url: https://www.codechef.com/START182B/problems/LPSS
