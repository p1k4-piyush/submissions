//  I can see you starin', honey
//  Like he's just your understudy
//  Like you'd get your knuckles bloody for me

#include "bits/stdc++.h"
using namespace std;

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/dbg.cpp"
#else
#define dbg(...)
#endif

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

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

    graph(int _n)
        : n(_n)
    {
        g.resize(n);
    }

    virtual int add(int from, int to, T cost) = 0;
};

//	https://github.com/the-tourist/algo/

template <typename T>
class digraph : public graph<T> {
public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

    digraph(int _n)
        : graph<T>(_n)
    {
    }

    int add(int from, int to, T cost = 1)
    {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int)edges.size();
        g[from].push_back(id);
        edges.push_back({ from, to, cost });
        return id;
    }

    digraph<T> reverse() const
    {
        digraph<T> rev(n);
        for (auto& e : edges) {
            rev.add(e.to, e.from, e.cost);
        }
        return rev;
    }
};

void evermore()
{
    int n;
    cin >> n;
    string s, s2;
    vector<int> set_t, set_f, unset_t, unset_f;

    for (int i = 0; i < n; i++) {
        cin >> s;
        cin >> s2;
        s = s + " " + s2;
        if (s == "set true") {
            set_t.push_back(i);
        } else if (s == "set false") {
            set_f.push_back(i);
        } else if (s == "unset true") {
            unset_t.push_back(i);
        } else {
            unset_f.push_back(i);
        }
        dbg(s);
    }

    dbg(set_t);
    dbg(set_f);
    dbg(unset_t);
    dbg(unset_f);
    digraph<int> g(n);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        g.add(l, r);
    }

    cout << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PIKA
    auto album_start_time = std::chrono::high_resolution_clock::now();
#endif
    int number_of_albums = 1;
    // cin >> number_of_albums;
    for (int number_of_song = 1; number_of_song <= number_of_albums; number_of_song++) {
        evermore();
        dbg(number_of_song);
    }
    dbg(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - album_start_time).count() * 1e-9);
    return 0;
}
