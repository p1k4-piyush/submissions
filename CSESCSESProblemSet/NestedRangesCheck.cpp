//  I knew you
//  Hand under my sweatshirt
//  Baby, kiss it better, I

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

ll n;
vector<tuple<ll,ll,ll>> arr;

void solve(){
    cin >> n;
    arr.assign(n,{0,0,0});
    
    for(ll i = 0; i < n; i++){
        cin >> get<0>(arr[i]) >> get<1>(arr[i]);
        get<2>(arr[i]) = i;
    }
    sort(arr.begin(),arr.end(),[&](auto i, auto j){
        if(get<0>(i) != get<0>(j)){
            return get<0>(i) < get<0>(j);
        }
        return get<1>(i) > get<1>(j);
    });
    vector<bool> ans1(n,0);
    vector<bool> ans2(n,0);
    ll mn = inf;
    for(ll i = n-1; i >= 0; i--){
        if(get<1>(arr[i]) >= mn){
            ans1[get<2>(arr[i])] = 1;
        }else{
            mn = get<1>(arr[i]);
        }
    }

    ll mx = -inf;
    for(ll i = 0; i < n; i++){
        if(get<1>(arr[i]) <= mx){
            ans2[get<2>(arr[i])] = 1;
        }else{
            mx = get<1>(arr[i]);
        }
    }
    for(auto i:ans1){
        cout << i << " ";
    }
    cout  << nl;
    for(auto i:ans2){
        cout << i << " ";
    }
    cout << nl;
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
// problem-url: https://cses.fi/problemset/task/2168
