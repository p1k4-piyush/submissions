//  50 years is a long time
//  Holiday House sat quietly on that beach
//  Free of women with madness, their men and bad habits
//  And then it was bought by me

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
vector<string> s;
string t;

void solve(){
    cin >> n;
    s.resize(n);
    
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    cin >> t;

    int m = t.size();
    vector<bool> used(m,0);
    vector<vector<char>> ans(m);

    for (auto &i:s){
        int cur = 0;
        for(auto j:i){
            if (t[cur] == j){
                used[cur]=1;
                cur++;
                if (cur == m){
                    cout << "NO"; return;
                }
            }else{
                ans[cur].push_back(j);
            }
        }
    }
    cout << "YES" << nl;
    for(int i = 0; i < m; i++){
        for (auto j:ans[i]){
            cout << j;
        }
        if (used[i]==1){
            cout << t[i];
        }
    }
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
// problem-url: https://codeforces.com/problemset/problem/2068/F
