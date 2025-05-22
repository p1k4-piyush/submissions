//  Salt air, and the rust on your door
//  I never needed anything more
//  Whispers of "Are you sure?"
//  "Never have I have before"

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

int n,m,a,b;

void solve(){
    cin >> n >> m >> a >> b;
    if(b>a){
        swap(a,b);
    }

    m-=n*b;
    dbg(m);
    a-=b;
    dbg(a);
    if(a==0){
        if (m == 0){
            cout << "Yes" << nl;
        }else{
            cout << "No" << nl;
        }
        return;
    }
    if((m>=0) && (m%a==0)&&(m/a <= n)){
        cout << "Yes";
    }else{
        cout << "No";
    }
    
    
    
    cout << nl;
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
// problem-url: https://www.codechef.com/START186B/problems/JUMPAB
