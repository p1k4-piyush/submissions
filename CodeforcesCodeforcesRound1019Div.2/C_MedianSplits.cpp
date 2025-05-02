//  Out of all the wrong arms right into that dive bar
//  Something wrapped all of my past mistakes in barbed wire
//  Chains around my demons, wool to brave the seasons
//  One single thread of gold tied me to you

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

int n,k;
vector<int> arr;

void solve(){
    cin >> n >> k;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector <int> pre(n+1,0),suf(n+1,0);
    
    for(int i = 0; i < n; i++){
        pre[i+1] = pre[i] + ((arr[i]<=k)?1:-1);
    }
    dbg(pre);
    
    
    for(int i = n-1; i >= 0; i--){
        suf[i] = suf[i+1] + ((arr[i]<=k)?1:-1);
    }
    dbg(suf);

    int l = 1e8;
    for(int i = 0; i < n-1; i++){
        if(pre[i+1]>=0){
            l=i;
            break;
        }
    }
    
    int r = -100;
    for(int i = n-1; i >= 1; i--){
        if(suf[i]>=0){
            r=i;
            break;
        }
    }

    dbg(l);
    dbg(r);
    if(l<r-1){
        cout << "YES" << nl; return;
    }

    int mn = 1e8;
    for(int i = 0; i < n-1; i++){
        if(pre[i+1] >= 0){
            if(pre[i+1]>=mn){
                cout << "YES" << nl; return;
            }else{
                mn = pre[i+1];
            }
        }
    }

    mn = 1e8;
    for(int i = n-1; i > 0; i--){
        if(suf[i] >= 0){
            if(suf[i]>=mn){
                cout << "YES" << nl; return;
            }else{
                mn = suf[i];
            }
        }
    }


    cout << "NO" << nl;
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2103/problem/C
