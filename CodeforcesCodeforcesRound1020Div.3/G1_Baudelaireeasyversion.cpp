//  Gold was color of the leaves
//  When I showed you around Centennial Park
//  Hell was the journey but it brought me heaven

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

int n;

void solve(){
    cin >> n;
    int x,y;
    for(int i = 0; i < n-1; i++){
        cin >> x >> y;
    }
    
    cout << "? 1 1 1" << nl;
    cout.flush();
    cin >> x;
    
    if(x == 1 || x == -1){
        vector<int> ans(n,0);
        ans[0] = x;
        for(int i = 1; i < n; i++){
            cout << "? 1 1 " << i+1 << nl;
            cout.flush();
            cin >> y;
            ans[i] = y-x;
        }
        cout << "! ";
        for(auto i:ans){
            cout << i << " ";
        }
        cout << nl;
        cout.flush();
        return;
    }

    if(x == 0){
        cout << "? 2 1" << nl;
        cout << "? 1 1 1" << nl;
        cout.flush();
        cin >> x;
    }
    
    vector<int> ans(n,0);
    ans[0] = x/2;
    vector<int> tt;
    for(int i = 1; i < n; i++){
        cout << "? 1 1 " << i+1 << nl;
        cout.flush();
        cin >> y;
        ans[i] = y-x;
        if(ans[i] == -x/2){
            tt.push_back(i+1);
        }
    }
    dbg(tt);
    dbg(x);
    dbg(ans);
    int l = 0, r = tt.size();
    cout << "? 2 1" << nl;
    cout.flush();
    while(r-l > 1){
        dbg(l,r);
        int t = (l+r)/2 - l;
        cout << "? 1 " << t << " ";
        for(int i = 0; i < t; i++){
            cout << tt[l+i] << " ";
        }
        cout << nl; cout.flush();
        cin >> y;
        if(-y == t*(x/2)){
            l = l+t;
        }else{
            r = l+t;
        }
    }
    cout << "? 2 1" << nl;
    cout.flush();


    ans[tt[l]-1] = -1*ans[tt[l]-1];

    cout << "! ";
    for(auto i:ans){
        cout << i << " ";
    }
    cout << nl;
    cout.flush();
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


// time-limit: 3000
// problem-url: https://codeforces.com/contest/2106/problem/G1
