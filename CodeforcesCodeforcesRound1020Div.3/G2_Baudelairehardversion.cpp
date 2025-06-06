//  Is it romantic how all my elegies eulogize me?
//  I'm not cut out for all these cynical clones
//  These hunters with cell phones

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

int n;
vector<int> arr;
vector<vector<int>> G;
vector<int> sz;
vector<bool> in_use;

void dfs1(int u, int p)
{
    sz[u] = 1;
    for (auto i : G[u]) {
        if (in_use[i]) {
            if (i == p)
                continue;
            dfs1(i, u);
            sz[u] += sz[i];
        }
    }
    // return sz[u];
}

int nn;
pair<int, int> dfs2(int u, int p)
{
    pair<int, int> res = { 0, u };
    pair<int, int> t = { 1e9, 1e9 };
    for (auto i : G[u]) {
        if (in_use[i]) {
            if (i == p) {
                res.first = max(res.first, nn - sz[u]);
                continue;
            }
            res.first = max(res.first, sz[i]);
            pair<int, int> t2 = dfs2(i, u);
            if (t2.first < t.first) {
                t = t2;
            }
        }
    }
    dbg(res);
    dbg(t);
    if (t.first < res.first) {
        return t;
    }
    return res;
}

vector<int> ans;
vector<int> dist;
void dfs3(int u, int p)
{
    for (auto i : G[u]) {
        if (i == p)
            continue;
        cout << "? 1 1 " << i + 1 << nl;
        cout.flush();
        int x;
        cin >> x;
        dist[i] = x;
        ans[i] = x - dist[u];
        dfs3(i, u);
    }
}

vector<int> GG(int t)
{
    vector<int> res;
    for (auto i : G[t]) {
        if (in_use[i])
            res.push_back(i);
    }
    return res;
}

vector<bool> temp;
int nnn;
void dfs(int u, int p)
{
    temp[u] = 1;
    nnn++;
    vector<int> G1 = GG(u);
    for (auto i : G1) {
        if (i == p)
            continue;
        dfs(i, u);
    }
}

void solve()
{
    cin >> n;
    int u, v;
    G.assign(n, vector<int>());
    sz.assign(n, 0);
    in_use.assign(n, 1);

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dbg(G);
    nn = n;
    int rt = 0;
    while (nn > 1) {
        dfs1(rt, rt);
        dbg(sz);
        int t = dfs2(rt, rt).second;
        dbg(t);
        vector<int> G1 = GG(t);
        int l = 0, r = G1.size();
        while (r - l > 1) {
            int tt = (l + r) / 2 - l;
            cout << "? 1 " << tt << " ";
            for (int i = 0; i < tt; i++) {
                cout << G1[l + i] + 1 << " ";
            }
            cout << nl;
            cout.flush();
            int x;
            cin >> x;
            cout << "? 2 " << t + 1 << nl;
            cout.flush();

            cout << "? 1 " << tt << " ";
            for (int i = 0; i < tt; i++) {
                cout << G1[l + i] + 1 << " ";
            }
            cout << nl;
            cout.flush();
            int y;
            cin >> y;
            if (abs(x - y) == 2 * tt) {
                l = l + tt;
            } else {
                r = l + tt;
            }
        }

        int o = G1[l];
        cout << "? 1 1 " << o + 1 << nl;
        cout.flush();
        int x;
        cin >> x;
        cout << "? 2 " << t + 1 << nl;
        cout.flush();
        cout << "? 1 1 " << o + 1 << nl;
        cout.flush();
        int y;
        cin >> y;
        if (x != y) {
            nn = 1;
            in_use.assign(n, 0);
            in_use[t] = 1;
            rt = t;
        } else {
            nnn = 0;
            temp.assign(n, 0);
            dfs(o, t);
            in_use = temp;
            nn = nnn;
            rt = o;
        }
    }
    dbg(rt + 1);
    ans.assign(n, 0);
    dist.assign(n, 0);
    cout << "? 1 1 " << rt + 1 << nl;
    cout.flush();
    int x;
    cin >> x;
    ans[rt] = x;
    dist[rt] = x;
    dfs3(rt, rt);
    cout << "! ";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << nl;
    cout.flush();
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// time-limit: 3000
// problem-url: https://codeforces.com/contest/2106/problem/G2
