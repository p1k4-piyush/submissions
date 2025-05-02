//  And it took you five whole minutes
//  To pack us up and leave me with it
//  Holdin' all this love out here in the hall

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

ll n,k;
vector<int> a,b;

void solve(){
    cin >> n >> k;
    a.assign(n,0);
    b.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    ll mn = 0;
    ll x,x2,y;
    ll mn2 = 9;
    for (int i = 0; i < n; i++){
        x = (a[i]-b[i]+9)%9;
        x2 = (b[i]-a[i]+9)%9;
        mn += min(x,x2);
        y = abs(x-x2);
        if(y&1){
            mn2 = min(mn2,y);
        }
    }

    if (k>=mn+mn2){
        cout << "Yes" << nl; return;
    }

    if(k < mn){
        cout << "No" << nl; return;
    }
    
    
    cout << (((k-mn)%2)?"No":"Yes") << nl;
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
// problem-url: https://www.codechef.com/START179B/problems/UNLOCKSAFE
