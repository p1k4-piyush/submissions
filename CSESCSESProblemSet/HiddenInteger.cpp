//  And they said
//  "There goes the last great American dynasty
//  Who knows, if she never showed up, what could've been
//  There goes the maddest woman this town has ever seen
//  She had a marvelous time ruining everything"

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
    ll l = 1,r = 1e9;
    string s;
    while(r > l){
        ll mid = (l+r)/2;
        cout << "? " << mid << nl;
        cout.flush();
        cin >> s;
        if(s[0]=='Y'){
            l = mid+1;
        }else{
            r = mid;
        }
    }
    cout << "! " << l << nl;
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
// problem-url: https://cses.fi/problemset/task/3112
