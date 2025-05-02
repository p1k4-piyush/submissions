//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
string s;
void solve(){
    cin >> s;
    n = s.size();
    dbg(n);
    stack<int> st;
    pair<int,int> ans = {0,1};
    int cur = 0;
    for(int i = 0; i < n; i++){
        if (s[i]=='('){
            st.push(i+1);
        }else{
            if (st.empty()){
                cur  = i+1;
                continue;
            }
            st.pop();
            ll x = 0;
            if (!st.empty()){
                x = i-st.top()+1;
            }else{
                x = i-cur+1;
            }
            if (x > ans.first){
                ans = {x,1};
                dbg(i);
            }else if(x == ans.first){
                ans.second++;
            }
        }
    }
    
    cout << ans.first << " " << ans.second << nl;
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


// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/5/C
