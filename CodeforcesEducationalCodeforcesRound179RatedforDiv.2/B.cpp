//  And you're tossing out blame, drunk on this pain
//  Crossing out the good years
//  And you're cursing my name, wishing I stayed
//  Look at how my tears ricochet

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/

template <typename T, size_t N, size_t M, size_t K>
array<array<T, K>, N> operator*(const array<array<T, M>, N>& a, const array<array<T, K>, M>& b)
{
    array<array<T, K>, N> c;
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < K; j++) {
            c[i][j] = 0;
            for (size_t k = 0; k < M; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

template <typename T>
vector<vector<T>> operator*(const vector<vector<T>>& a, const vector<vector<T>>& b)
{
    if (a.empty() || b.empty()) {
        return { {} };
    }
    vector<vector<T>> c(a.size(), vector<T>(b[0].size()));
    for (int i = 0; i < static_cast<int>(c.size()); i++) {
        for (int j = 0; j < static_cast<int>(c[0].size()); j++) {
            c[i][j] = 0;
            for (int k = 0; k < static_cast<int>(b.size()); k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

template <typename T>
vector<vector<T>>& operator*=(vector<vector<T>>& a, const vector<vector<T>>& b)
{
    return a = a * b;
}

template <typename T, typename U>
vector<vector<T>> power(const vector<vector<T>>& a, const U& b)
{
    assert(b >= 0);
    vector<U> binary;
    U bb = b;
    while (bb > 0) {
        binary.push_back(bb & 1);
        bb >>= 1;
    }
    vector<vector<T>> res(a.size(), vector<T>(a.size()));
    for (int i = 0; i < static_cast<int>(a.size()); i++) {
        res[i][i] = 1;
    }
    for (int j = (int)binary.size() - 1; j >= 0; j--) {
        res *= res;
        if (binary[j] == 1) {
            res *= a;
        }
    }
    return res;
}

ll fib(ll n)
{
    vector<vector<ll>> t = { { 1, 1 }, { 1, 0 } };
    return power(t, n)[1][0];
}

void evermore()
{
    ll n, m;
    cin >> n >> m;
    ll t = fib(n + 1);
    ll t2 = fib(n + 2);
    dbg(t);
    vector<ll> ans = { t, t, t2 };
    for (int i = 0; i < m; i++) {
        vector<ll> tt(3);
        cin >> tt[0] >> tt[1] >> tt[2];
        sort(tt.begin(), tt.end());
        bool c = 1;
        for (int j = 0; j < 3; j++) {
            if (tt[j] < ans[j]) {
                cout << "0";
                c = 0;
                break;
            }
        }
        if (c) {
            cout << "1";
        }
    }

    cout << nl;
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while (number_of_albums--) {
        evermore();
    }
    return 0;
}
// time-limit: 3000
