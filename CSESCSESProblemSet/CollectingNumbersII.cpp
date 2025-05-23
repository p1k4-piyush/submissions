//  You're not my homeland anymore
//  So what am I defending now?
//  You were my town
//  Now I'm in exile, seein' you out

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

int n,m;
vector<int> pos;
vector<int> arr;

void solve(){
    cin >> n >> m;
    pos.assign(n,-1);
    arr.assign(n,-1);
    int t;
    int ans = 0;
    
    for(int i = 0; i < n; i++){
        cin >> t;
        t--;
        pos[t] = i;
        arr[i] = t;
        if(t && (pos[t-1]!=-1)){
            continue;
        }
        ans++;
    }

    int l,r;
    while(m--){
        cin >> l >> r;
        l--; r--;
        dbg(arr);
        dbg(pos);
        dbg(ans);
        set<pair<int,int>> tt;
        if(arr[l] != n-1){
            tt.insert({arr[l],arr[l]+1});
        }
        if(arr[l] != 0){
            tt.insert({arr[l]-1,arr[l]});
        }
        if(arr[r] != 0){
            tt.insert({arr[r]-1,arr[r]});
        }
        if(arr[r] != n-1){
            tt.insert({arr[r],arr[r]+1});
        }
        for(auto i:tt){
            if(pos[i.first] > pos[i.second]){
                ans--;
            }
        }
        swap(pos[arr[l]],pos[arr[r]]);
        swap(arr[l],arr[r]);
        for(auto i:tt){
            if(pos[i.first] > pos[i.second]){
                ans++;
            }
        }

        cout << ans << nl;
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/2217
