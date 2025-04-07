//  We were something, don't you think so?
//  Rosé flowing with your chosen family
//  And it would've been sweet
//  If it could've been me

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
ll k;
vector<ll> a2,b2;


void solve(){
    cin >> n >> k;
    a2.assign(n,0);
    b2.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> a2[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b2[i];
    }
    if(k >= accumulate(a2.begin(),a2.end(),(ll)0)){
        cout << "0" << nl; return;
    }

    vector<ll> diff(n,0);
    bool cc = 1;
    
    for(int i = 0; i < n; i++){
        diff[i] = b2[i] - a2[i];
        if (diff[i]<0) cc = 0;
    }
    
    if(cc){
        cout << "1" << nl; return;
    }

    ll cur = 0;
    pair<ll,int>mx = {0,0};

    for(int i = 0; i < 2*n; i++){
        if (cur < (ll)0){
            cur = 0;
        }
        cur += diff[i%n];
        if (cur > mx.first){
            mx = {cur,i+1};
        }
    }
    
    auto cus = [](const pair<ll,int> &a,const pair<ll,int> &b){
        return a.second > b.second;
    };

    vector<ll> a(n),b(n);

    for (int i = 0; i < n; i++){
        a[n-i-1] = a2[(i+mx.second)%n];
        b[n-i-1] = b2[(i+mx.second)%n];
    }

    ll lo = 1, hi = n;
    while(hi >= lo){
        ll mid = (hi+lo)/(ll)2;
        set<pair<ll,int>,decltype(cus)> s(cus);
        ll kk = k;
        for(int i = 0; i < n; i++){
            ll d = a[i]-b[i];
            if (d>=0){
                while(d>0){
                    auto it = s.begin();
                    if (i-it->second+1 > mid){
                        kk -= d;
                        break;
                    }
                    if (it->first > d){
                        s.erase(it);
                        s.insert({it->first-d,it->second});
                        d = 0;
                    }else{
                        d -= it->first;
                        s.erase(it);
                    }
                }
            }else{
                s.insert({-d,i});
            }
        }
        if (kk >= (ll)0){
            hi = mid-1;
        }else{
            lo = mid+1;
        }

    }
    
    
    cout << hi+(ll)1 << nl;
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
// problem-url: https://codeforces.com/contest/2090/problem/E2
