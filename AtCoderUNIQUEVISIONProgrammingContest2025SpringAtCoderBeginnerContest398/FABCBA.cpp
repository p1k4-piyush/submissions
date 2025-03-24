//  I can see you starin', honey
//  Like he's just your understudy
//  Like you'd get your knuckles bloody for me


#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif
vector<int> pre;
string s,s1,s2;
int n;

void prefix() {
    for(int i = 1; i < n; i++) {
        int j = pre[i-1];
        while(j > 0 && s[i] != s[j]) {
            j = pre[j-1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pre[i] = j;
    }
}

void solve(){
    cin >> s2;
    s1 = s2;
    reverse(all(s1));
    s = s1+"#"+s2;
    n=s.size();

    pre.assign(n,0); 
    prefix(); 
     
    dbg(2*s2.size() - pre[n-1]);

    cout << s2;
    for(int i = pre[n-1]; i < s1.size();i++){
        cout << s1[i];
    }
    // cout << 2*s2.size() - pre[n-1] << nl;
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
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_f
