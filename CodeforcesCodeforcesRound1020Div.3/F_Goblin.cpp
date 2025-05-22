//  Bold was waitress on our three year trip
//  Getting lunch down by the lakes
//  She said I looked like an American singer

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
    cin >> n >> s;
    vector<ll> top(n,0), bottom(n,0);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            top[i] = i;
            bottom[i] = n - i - 1;
            if(i != 0){
                top[i] += top[i-1];
                bottom[i] += bottom[i-1];
            }
        }else{
            top[i] = 1;
            if(i != 0){
                top[i] += bottom[i-1];
            }
        }
        ans = max(ans,max(top[i],bottom[i]));
    }

    
    cout << ans << nl;
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
// problem-url: https://codeforces.com/problemset/problem/2106/F
