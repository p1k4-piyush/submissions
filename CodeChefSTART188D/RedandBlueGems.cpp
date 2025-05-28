//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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



void evermore(){
    ll r,b,p,q;
    cin >> r >> b >> p >> q;
    cout << max(r*p,b*q) << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    while(number_of_albums--){
        evermore();
    }
    return 0;
}


// time-limit: 1000
// problem-url: https://www.codechef.com/START188D/problems/REDBLUEGEM
