//  I was so ahead of the curve, the curve became a sphere
//  Fell behind all my classmates, and I ended up here
//  Pouring out my heart to a stranger
//  But I didn't pour the whiskey

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

ll f(ll a, ll b){
    ll t = b;
    while(t%ll(2) == 0){
        t /= ll(2);
    }
    if(a%t || b%a){
        return b/t;
    }else{
        return b/t-ll(2)*a/t+ll(1);
    }
}

void evermore(){
    ll n,k;
    cin >> n >> k;
    vector<ll> arr(n,0);
    for(auto &i:arr){
        cin >> i;
    }
    vector<ll> L(n,0), R(n,0);
    for(int i = 1; i < n; i++){
        L[i] = L[i-1] + f(arr[i],arr[i-1]);
    }
    for(int i = n-2; i >= 0; i--){
        R[i] = R[i+1]+f(arr[i],arr[i+1]);
    }
    for(int i = 0; i < n; i++){
        ll t = arr[i];
        while(t%2 == 0) t/= ll(2);
        if(arr[i]/t+L[i]+R[i]>=k){
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
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
// problem-url: https://codeforces.com/contest/2114/problem/G
