//  Time, wonderous time 
//  Gave me the blues and then purple pink skies
//  And it's cool baby with me

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(1e12);
const char nl = '\n';



ll n;
const int N = 10000000;
vector<int> lp(N+1);
vector<int> fc(N+1);
vector<ll> sq;
vector<int> pr;


void solve(){
    cin >> n;
    
    auto it = upper_bound(sq.begin(),sq.end(),n);
    it--;
    cout << *it << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    fc[1] = 0;
    for (int i=2; i <= N; ++i) {
        if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j) {
        lp[i * pr[j]] = pr[j];
        if (pr[j] == lp[i]) {
            break;
        }
        }
    }
    for(int i = 2; i <= N; i++){
        int tt = lp[i];
        int x = i/tt;
        if(x>1 && lp[x]==tt){
            fc[i] = fc[x];
        }else{
            fc[i] = fc[x]+1;
        }
    }
    for(int i = 2; i <= N; i++){
        if(fc[i] == 2){
            ll sq1 = ll(i)*ll(i);
            if(sq1 <= INF){
                sq.push_back(sq1);
            }
        }
    }



    while(t--){
        solve();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc400/tasks/abc400_e
