//  We always walked a very thin line
//  You didn't even hear me out
//  You never gave a warning sign
//  All this time

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

int n,m;
vector<set<int>> arr;
vector<tuple<int,int,int>> ans;

void solve(){
    cin >> n >> m;
    arr.assign(n,set<int>());
    ans.resize(0);
    int u,v;

    for(int i = 0; i < m; i++){
        cin >> u >> v;
        u--; v--;
        arr[u].insert(v);
        arr[v].insert(u);
    }

    for(int i = 0; i < n; i++){
        while(arr[i].size() >= 2){
            auto u = *arr[i].begin();
            arr[i].erase(arr[i].begin());
            arr[u].erase(i);
            auto v = *arr[i].begin();
            arr[i].erase(arr[i].begin());
            arr[v].erase(i);
            ans.push_back({i,u,v});
            if(arr[u].count(v)){
                arr[u].erase(v);
                arr[v].erase(u);
            }else{
                arr[u].insert(v);
                arr[v].insert(u);
            }
        }
    }
    dbg(arr); 
    vector<int> s;
    vector<pair<int,int>> s2;
    for (int i = 0; i < n; i++){
        if (arr[i].size() == 0){
            s.push_back(i);
        }else if(*arr[i].begin()>i){
            s2.push_back({i,*arr[i].begin()});
        }
    }

    if (!s2.empty()){
        auto [x,y] = s2.back();
        s2.pop_back();
        for(auto i:s){
            ans.push_back({i,x,y});
            y = i;
        }
        for(auto [i,j]:s2){
            ans.push_back({i,j,y});
        }
    }

    dbg(ans);
    cout << ans.size() << nl;
    for(auto [i,j,k]:ans){
        cout << i+1 << " " << j+1 << " " << k+1 << nl;
    }

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


// time-limit: 3000
// problem-url: https://codeforces.com/problemset/problem/2029/D
