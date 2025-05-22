//  50 years is a long time
//  Holiday House sat quietly on that beach
//  Free of women with madness, their men and bad habits
//  And then it was bought by me

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

void solve(){
    n = 5;
    priority_queue<int,vector<int>,greater<int>> s;
    int sum = 0;
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        s.push(t);
        sum += t;
    }
    
    int ans = 0;
    while(sum < 35){
        sum += 10- s.top();
        dbg(sum);
        s.pop();
        ans += 100;
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


// time-limit: 1000
// problem-url: https://www.codechef.com/START186B/problems/APPROVAL
