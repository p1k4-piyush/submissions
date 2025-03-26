//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing

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


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



ll s,k;
vector<bool> dp1,dp2;

void solve(){
    cin >> s >> k;
    
    if (s%k == 0){
        cout << k << nl; return;
    }
    if (s >= 2ll*k*k){
        cout << max((ll)1,k-2) << nl; return;
    }

    dp1.assign(s+1,0);
    dp2.assign(s+1,0);
    bool p = 0;
    for(int i = 0; i < s+1; i+= k){
        dp1[i] = 1;
    }
    // dbg(dp1);
    // dbg(dp2);
    // k--;
    while(k>=1){
        k--;
        if(p){
            for(int i = 0; i + k < s+1; i++){
                if (dp1[i]){
                    for(int j = i+k; j < s+1 && !(dp2[j]); j+=k){
                        dp2[j] = 1;
                    }
                }
            }
        }else{
            for(int i = s; i >= k; i--){
                if (dp1[i]){
                    for(int j = i-k; j >= 0 && !(dp2[j]); j-=k){
                        dp2[j] = 1;
                    }
                }
            }
        }
        if(dp2[s]){
            cout << k << nl; return;
        }
        dp1=dp2;
        dp2.assign(s+1,0);
        p^=1;
    }

    
    
    cout << 1 << nl;
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
// problem-url: https://codeforces.com/contest/2091/problem/G
