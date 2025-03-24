//  I never learned to read your mind
//  I couldn't turn things around
//  'Cause you never gave a warning sign
//  All this time

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
vector<int> arr;

void solve(){
    cout << stoi("010101010101010101010101010101",0,2) << nl;
    cout.flush();
    ll x,y;
    cin >> y;
    cout << stoi("101010101010101010101010101010",0,2) << nl;
    cout.flush();
    cin >> x;

    cout << "!" << nl; cout.flush();
    ll m; cin >> m;

    ll t1 = 0,t2 = 0;
    for (int i = 0; i<30;i+=2){
        ll c1 = (x>>i)&1ll;
        ll c2 = (x>>(i+1))&1ll;

        if (c2){
            t1 += (1ll<<i);
            t2 += (1ll<<i);
        }else if (c1){
            t2 += (1ll<<i);
        }

        x -= (1ll<<(i+2));
    }
    
    y-=2;
    for (int i = 1; i<30;i+=2){
        ll c1 = (y>>i)&1ll;
        ll c2 = (y>>(i+1))&1ll;

        if (!c2 && c1){
            t2 += (1ll<<i);
        }else if (c2 && !c1){
            t1 += (1ll<<i);
            t2 += (1ll<<i);
        }
        y -= (1ll<<(i+2));
    }
    
    ll ans = 0;
    for(int i = 0; i<30; i++){
        ll c = (m>>i)&1;
        ll c1 = (t1>>i)&1;
        ll c2 = (t2>>i)&1;
        if (c|c1){
            ans += (1ll<<(i+1));
        }else if (c2){
            ans += (1ll<<i);
        }
    }

    
    cout << ans << nl; cout.flush();
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
// problem-url: https://codeforces.com/problemset/problem/2077/B
