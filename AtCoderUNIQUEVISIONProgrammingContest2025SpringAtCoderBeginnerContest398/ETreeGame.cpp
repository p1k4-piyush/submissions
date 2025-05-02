//  I knew you
//  Leavin' like a father
//  Running like water, I
//  And when you are young, they assume you know nothing



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

const int MAX_N = 2e5+100;
int n;
vector<vector<int>> arr;

int c1 = 0,c2=0;
vector<int> a1,a2;

void dfs(int u, int p, bool cur){
    if (cur){
        c1++;
        a1.push_back(u);
    }else{
        c2++;
        a2.push_back(u);
    }
    for(auto i:arr[u]){
        if (i == p) continue;
        dfs(i,u,!cur);
    }
}

void solve(){
    cin >> n;
    arr.assign(n,vector<int>());
    
    vector<pair<int,int>> vv;
    int u,v;

    for(int i = 0; i < n-1; i++){
        cin >> u >> v; u--; v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
        vv.push_back({u,v});
        vv.push_back({v,u});
    }

    if (n == 1){
        cout << "Second" << nl; cout.flush();
        return;
    }
    dfs(0,0,0);
    set<pair<int,int>> s;
    for (auto i:a1){
        for(auto j:a2){
            if (i == j) continue;
            s.insert({i,j});
            s.insert({j,i});
        }
    }
    
    for(auto i:vv){
        s.erase(i);
    }

    dbg(s);
    dbg((s.size()>>1)&1);
    if (((s.size()>>1)&1)){
        cout << "First" << nl; cout.flush();
        while(!s.empty()){
            pair<int,int> pp = *s.begin();
            u = pp.first; v = pp.second;
            cout << u+1 << " " << v+1 << nl; cout.flush();
            s.erase({u,v});
            s.erase({v,u});
            if (s.empty()) break;
            cin >> u >> v;
            u--; v--;
            s.erase({u,v});
            s.erase({v,u});
        }
    }else{
        cout << "Second" << nl; cout.flush();
        cin >> u >> v;
        u--; v--;
        s.erase({u,v});
        s.erase({v,u});
        while(!s.empty()){
            pair<int,int> pp = *s.begin();
            u = pp.first; v = pp.second;
            cout << u+1 << " " << v+1 << nl; cout.flush();
            s.erase({u,v});
            s.erase({v,u});
            if (s.empty()) break;
            cin >> u >> v;
            u--; v--;
            s.erase({u,v});
            s.erase({v,u});
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
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_e

