//  You taught me a secret language I can't speak with anyone else
//  And you know damn well
//  For you, I would ruin myself
//  A million little times

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif



void evermore(){
    int n;
    cin >> n;
    string s; cin >> s;
    vector<int> pre(n+1,0), suf(n+1,0);
    for(int i = 1; i < n; i++){
        if(s[i-1]!='C'){
            pre[i] = pre[i-1]+(s[i-1]=='A');
        }
    }
    for(int i = n-2; i >= 0; i--){
        if(s[i+1]!='A'){
            suf[i] = suf[i+1]+(s[i+1]=='C');
        }
    }
    dbg(pre);
    dbg(suf);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'B'){
            ans += max(pre[i],suf[i]);
        }
    }
    
    cout << ans << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while(number_of_albums--){
        evermore();
    }
    return 0;
}


// time-limit: 1000
// problem-url: https://www.codechef.com/START188A/problems/SWAPSTR
