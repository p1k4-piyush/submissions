//  Out of all the wrong arms right into that dive bar
//  Something wrapped all of my past mistakes in barbed wire
//  Chains around my demons, wool to brave the seasons
//  One single thread of gold tied me to you

#include <algorithm>
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
string s;

void solve(){
    cin >> s;
    n = s.size();
    set<string> ans;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    dbg(v);
    
    do{
        string s1;
        for(auto i:v){
            s1+=s[i-1];
        }
        ans.insert(s1);
    }while(next_permutation(v.begin(),v.end()));

    cout << ans.size() << nl;
    for(auto i:ans){
        cout << i << nl;
    }
    dbg(ans);
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
// problem-url: https://cses.fi/problemset/task/1622
