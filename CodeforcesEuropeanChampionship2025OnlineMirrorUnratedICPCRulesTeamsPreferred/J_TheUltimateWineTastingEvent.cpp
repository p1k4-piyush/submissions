//  Time, wonderous time 
//  Gave me the blues and then purple pink skies
//  And it's cool baby with me

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
    cin >> n;
    cin >> s;

    int c = 0;
    for(int i = 0; i < n; i++){
        if (s[i] == 'W'){
            c++;
        }
    }

    if(c&1){
        cout << "NO" << nl;
        return;
    }
    for(int i = 0; i < c/2; i++){
        if (s[i] == 'R'){
            cout << "NO" << nl;
            return;
        }
    }
    
    for(int i = size(s)- c/2; i < size(s); i++){
        if (s[i] == 'W'){
            cout << "NO" << nl;
            return;
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


// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/2068/J
