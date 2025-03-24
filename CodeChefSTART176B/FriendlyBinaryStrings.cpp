//  And if I'm dead to you, why are you at the wake?
//  Cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n;

void solve(){
    cin >> n;
    
    int zz = 0,oz = 0, zo = 0, oo = 0;

    string a,b;
    cin >> a >> b;
    for(int i = 0; i < n; i++){
        if (a[i] == '1' && b[i] == '1'){
            oo++;
        }else if(a[i] == '0' && b[i] == '1'){
            zo++;
        }else if(a[i] == '1' && b[i] == '0'){
            oz++;
        }else{
            zz++;
        }
    }
    
    if (n&1){
        if (oo&1 && zz&1){
            cout << "NO" << nl; return;
        }
    }else{
        if (oo&1 || zz&1){
            cout << "NO" << nl; return;
        }
    }
    
    
    cout << "YES" << nl;
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
// problem-url: https://www.codechef.com/START176B/problems/MSATP
