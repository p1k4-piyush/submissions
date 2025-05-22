//  I can see you standing, honey
//  With his arms around your body
//  Laughin', but the joke's not funny at all

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
vector<int> arr;
string s;

void solve(){
    cin >> s;
    n = s.size();
    arr.assign(26,0);

    for(auto i:s){
        arr[i-'A']++;
    }

    if(n&1){
        bool c = 1;
        int tt = -1;
        string ans;
        for(int i = 0; i < 26; i++){
            if (c && (arr[i]&1)){
                c = 0;
                tt = i;
            }else if (arr[i]&1){
                cout << "NO SOLUTION" << nl;
                return;
            }
            for(int j = 0; j < arr[i]/2; j++){
                ans+=char('A'+i);
            }
        }
        cout << ans << char('A'+tt);
        reverse(ans.begin(),ans.end());
        cout << ans << nl;
    }else{
        string ans;
        for(int i = 0; i < 26; i++){
            if (arr[i]&1){
                cout << "NO SOLUTION" << nl;
                return;
            }
            for(int j = 0; j < arr[i]/2; j++){
                ans+=char('A'+i);
            }
        }
        cout << ans;
        reverse(ans.begin(),ans.end());
        cout << ans << nl;
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
// problem-url: https://cses.fi/problemset/task/1755
