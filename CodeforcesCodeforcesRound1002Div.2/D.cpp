

//  Even on my worst day, did I deserve, babe
//  All the hell you gave me?
//  'Cause I loved you, swear I loved you
//  'Til my dying day

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

struct State {
    ll cost;
    int a, b;
    bool operator>(const State &other) const {
        return cost > other.cost;
    }
};

void solve(){
    int n, s1, s2; 
    cin >> n >> s1 >> s2;
    
    int m1; 
    cin >> m1;
    vector<vector<int>> graph1(n+1);
    for (int i = 0; i < m1; i++){
        int u, v;
        cin >> u >> v;
        graph1[u].push_back(v);
        graph1[v].push_back(u);
    }
    
    int m2;
    cin >> m2;
    vector<vector<int>> graph2(n+1);
    for (int i = 0; i < m2; i++){
        int u, v;
        cin >> u >> v;
        graph2[u].push_back(v);
        graph2[v].push_back(u);
    }
    
    vector<bool> win(n+1, false);
    vector<unordered_set<int>> set1(n+1), set2(n+1);
    for (int v = 1; v <= n; v++){
        for (int nb : graph1[v])
            set1[v].insert(nb);
        for (int nb : graph2[v])
            set2[v].insert(nb);
    }
    for (int v = 1; v <= n; v++){
        for (int nb : set1[v]){
            if (set2[v].find(nb) != set2[v].end()){
                win[v] = true;
                break;
            }
        }
    }
    
    if(s1 == s2 && win[s1]){
        cout << 0 << nl;
        return;
    }
    
    auto idx = [n](int a, int b) -> int {
        return (a - 1) * n + (b - 1);
    };
    int totalStates = n * n;
    vector<ll> dist(totalStates, INF);
    
    priority_queue<State, vector<State>, greater<State>> pq;
    int startIdx = idx(s1, s2);
    dist[startIdx] = 0;
    pq.push({0, s1, s2});
    
    ll ans = -1;
    while(!pq.empty()){
        State cur = pq.top();
        pq.pop();
        int a = cur.a, b = cur.b;
        ll d = cur.cost;
        int curIndex = idx(a, b);
        if(d != dist[curIndex])
            continue;
        
        if(a == b && win[a]){
            ans = d;
            break;
        }
        
        const vector<int>& nbList1 = graph1[a];
        const vector<int>& nbList2 = graph2[b];
        
        if(nbList1.size() <= nbList2.size()){
            for (int a2 : nbList1){
                for (int b2 : nbList2){
                    int newIndex = idx(a2, b2);
                    ll nd = d + ll(abs(a2 - b2));
                    if(nd < dist[newIndex]){
                        dist[newIndex] = nd;
                        pq.push({nd, a2, b2});
                    }
                }
            }
        } else {
            for (int b2 : nbList2){
                for (int a2 : nbList1){
                    int newIndex = idx(a2, b2);
                    ll nd = d + ll(abs(a2 - b2));
                    if(nd < dist[newIndex]){
                        dist[newIndex] = nd;
                        pq.push({nd, a2, b2});
                    }
                }
            }
        }
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
