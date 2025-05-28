//  I was so ahead of the curve, the curve became a sphere
//  Fell behind all my classmates, and I ended up here
//  Pouring out my heart to a stranger
//  But I didn't pour the whiskey

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif


//	https://github.com/the-tourist/algo/


template <typename T>
class graph {
    public:
        struct edge {
            int from;
            int to;
            T cost;
        };

        vector<edge> edges;
        vector<vector<int>> g;
        int n;

        graph(int _n) : n(_n) {
            g.resize(n);
        }

        virtual int add(int from, int to, T cost) = 0;
};



//	https://github.com/the-tourist/algo/


template <typename T>
class undigraph : public graph<T> {
    public:
        using graph<T>::edges;
        using graph<T>::g;
        using graph<T>::n;

        undigraph(int _n) : graph<T>(_n) {

        }

        int add(int from, int to, T cost = 1) {
            assert(0 <= from && from < n && 0 <= to && to < n);
            int id = (int) edges.size();
            g[from].push_back(id);
            g[to].push_back(id);
            edges.push_back({from, to, cost});
            return id;
        }
};



//	https://github.com/the-tourist/algo/


template <typename T>
vector<int> find_eulerian_path(const graph<T> &g, int &root) {
    // in_deg and out_deg are fake for undigraph!
    vector<int> in_deg(g.n, 0);
    vector<int> out_deg(g.n, 0);
    int cnt_edges = 0;
    for (int id = 0; id < (int) g.edges.size(); id++) {
        cnt_edges++;
        auto &e = g.edges[id];
        out_deg[e.from]++;
        in_deg[e.to]++;
    }
    root = -1;
    int odd = 0;
    for (int i = 0; i < g.n; i++) {
        if ((in_deg[i] + out_deg[i]) % 2 == 1) {
            odd++;
            if (root == -1 || out_deg[i] - in_deg[i] > out_deg[root] - in_deg[root]) {
                root = i;
            }
        }
    }
    if (odd > 2) {  
        root = -1;
        return vector<int>();
    }
    if (root == -1) {
        root = 0;
        while (root < g.n && in_deg[root] + out_deg[root] == 0) {
            root++;
        }
        if (root == g.n) {
            // an empty path
            root = 0;
            return vector<int>();
        }
    }
    vector<bool> used(g.edges.size(), false);
    vector<int> ptr(g.n, 0);
    vector<int> balance(g.n, 0);
    vector<int> res(cnt_edges);
    int stack_ptr = 0;
    int write_ptr = cnt_edges;
    int v = root;
    while (true) {
        bool found = false;
        while (ptr[v] < (int) g.g[v].size()) {
            int id = g.g[v][ptr[v]++];
            if (used[id]) {
                continue;
            }
            used[id] = true;
            res[stack_ptr++] = id;
            auto &e = g.edges[id];
            balance[v]++;
            v ^= e.from ^ e.to;
            balance[v]--;
            found = true;
            break;
        }
        if (!found) {
            if (stack_ptr == 0) {
                break;
            }
            int id = res[--stack_ptr];
            res[--write_ptr] = id;
            auto &e = g.edges[id];
            v ^= e.from ^ e.to;
        }
    }
    int disbalance = 0;
    for (int i = 0; i < g.n; i++) {
        disbalance += abs(balance[i]);
    }
    if (write_ptr != 0 || disbalance > 2) {
        root = -1;
        return vector<int>();
    }
    return res;
    // returns edge ids in the path (or the cycle if it exists)
    // root == -1 if there is no path
    // (or res.empty(), but this is also true when there are no edges)
}


void evermore(){
    int n,t,tt;
    cin >> n;
    int cur1 = 0, cur2 = 0;
    map<int,int> mp;
    map<int,int> mp2;
    vector<pair<int,int>> in;
    
    for(int i = 0; i < n; i++){
        cin >> t >> tt;
        if(!mp.contains(t)){
            mp[t] = cur1++;
        }
        if(!mp2.contains(tt)){
            mp2[tt] = cur2++;
        }
        in.push_back({t,tt});
    }
    
    undigraph<int> G(cur1+cur2);
    for(auto i:in){
        G.add(mp[i.first],mp2[i.second]+cur1);
    }

    int root;
    vector<int> ans = find_eulerian_path(G, root);
    if (root == -1){
        cout << "NO";
    }else{
        cout << "YES" << nl;
        for (auto i:ans){
            cout << i+1 << " ";
        }
    }

    cout << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while(number_of_albums--){
        evermore();
    }
    return 0;
}


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2110/problem/E
