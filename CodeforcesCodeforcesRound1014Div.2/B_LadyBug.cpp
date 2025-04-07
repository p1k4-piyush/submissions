//  You had to kill me, but it killed you just the same
//  Cursing my name, wishing I stayed
//  You turned into your worst fears

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
string a,b;

void solve(){
    cin >> n;
    cin >> a >> b;
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++){
        if(i&1){
            c1+=(a[i]=='0');
            c2+=(b[i]=='0');
            c1--;
        }else{
            c2+=(a[i]=='0');
            c1+=(b[i]=='0');
            c2--;
        }
    }
    dbg("e");
    cerr << "E" << nl;  
    cout << ((min(c1,c2)>=0)?"YES":"NO") << nl;
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
// problem-url: https://codeforces.com/contest/2092/problem/B
