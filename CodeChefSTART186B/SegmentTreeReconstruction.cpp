//  Out of all the wrong arms right into that dive bar
//  Something wrapped all of my past mistakes in barbed wire
//  Chains around my demons, wool to brave the seasons
//  One single thread of gold tied me to you

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

ll n,k;
vector<ll> vals;

void solve(){
    cin >> n >> k;
    
    vector<ll> rem(n+2,0);
    vector<ll> rem2(n+2,0);
    rem[n] = 1;
    for(int i = n-1; i>=0;i--){
        rem[i]=rem[i+1]*ll(2);
    }

    for(int i = n; i >= 0; i--){
        if(rem[i]>rem[i+1] && k >= vals[i]){
            ll r = rem[i]-rem[i+1];
            ll tt = min(k/vals[i],r);
            k -= vals[i]*tt;
            ll ttt=tt;
            // rem2[i]+=tt;
            for(int j = i; j >= 0; j--){
                rem2[j]+=ttt;
                rem[j]-=ttt;
                ttt *=2;
            }
        }
    }
    string s(ll(1)<<n,'0');

    ll cur = 0;
    for(int i = n; i >= 0; i--){
        ll gap = ll(1)<<(i);
        ll ttt = rem2[i];
        for(int j = 0; j < i; j++){
            rem2[j] -= rem2[i]*gap/(ll(1)<<j);
        }
        rem2[i] = 0;
        while(ttt>0){
            dbg(gap);
            for(int ii = 0; ((ii < gap) && (cur < (1<<n))); ii++){
                s[cur] = '1';
                cur++;
            }
            if (ttt == 1){
                break;
            }
            for(int ii = 0; ((ii < gap) && (cur < (1<<n))); ii++){
                cur++;
            }

            ttt--;
        }
        dbg(s);
        dbg(rem2);
    }

    if (k!=0){
        cout << "No";
    }else{
        cout << "Yes" << nl;
        cout << s;
    }

    
    cout << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    vals.assign(22,1);
    for(int i = 1; i < 22; i++){
        vals[i] = vals[i-1]*ll(2) + ll(1);
    }
    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://www.codechef.com/START186B/problems/SEGTREECON
