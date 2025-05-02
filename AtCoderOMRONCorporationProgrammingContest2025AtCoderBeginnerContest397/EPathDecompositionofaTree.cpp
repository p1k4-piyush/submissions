//  But I knew you'd linger like a tattoo kiss
//  I knew you'd haunt all of my what-ifs
//  The smell of smoke would hang around this long
//  'Cause I knew everything wehn I was young

#include <bits/stdc++.h>
using namespace std;

#define int __int64_t
typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,k;
vector<vector<int>> arr;
vector<int> par;

void dfs(int v, int p){
    par[v] = p;
    for (auto i:arr[v]){
        if (par[i]!=-2) continue;
        dfs(i,v);
    }
}
void solve(){
    cin >> n >> k;
     if (k == 1){
        cout << "YES"; return;
    }

    arr.assign(n*k,vector<int>());
    int u,v;
    for(int i = 0; i < n*k -1; i++){
        cin >> u >> v;
        u--; v--;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int> deg(n*k,0);
    for (int i = 0; i < n*k;i++){
        deg[i] = arr[i].size();
    }
    par.assign(n*k,-2);
    dfs(0,-1);

    vector<bool> used(n*k,0);

    dbg(par);
    queue<int> q;
    for (int i = 1; i < n*k; i++){
        if (deg[i] == 1) q.push(i);
    }
    int c = 0;
    while (!q.empty()){
        int cur = q.front();
        q.pop();
        if (used[cur]) continue;
        vector<int> current;
        while (cur != -1 && current.size() < k && !used[cur]){
            current.push_back(cur);
            used[cur] = 1;
            cur = par[cur];
            c++;
        }
        
        if(current.size() != k){
            dbg(current);
            dbg(used);

            cout << "No"; return;
        }

        for(auto i:current){
            for(auto j:arr[i]){
                deg[j]--;
                if (deg[j] == 1){
                    q.push(j);
                }
            }
            deg[i] = 0;
        }

    }
       
    if (c != n*k){
        dbg(c);
        cout << "No"; return;
    }
    
    cout << "Yes";
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
