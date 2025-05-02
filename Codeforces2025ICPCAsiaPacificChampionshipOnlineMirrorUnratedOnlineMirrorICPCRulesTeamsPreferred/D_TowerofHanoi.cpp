//  I guess you never know, never know
//  And if you wanted me, you really should have showed
//  And if you never bleed, you're never gonna grow
//  And it's alright now

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/


const int MOD = 998244353;
// const int MOD = 1000000007;


template <typename T>
T inverse(T a, T m) {
    T u = 0, v = 1;
    while (a != 0) {
        T t = m / a;
        m -= t * a; swap(a, m);
        u -= t * v; swap(u, v);
    }
    assert(m == 1);
    return u;
}

template <typename T>
class Modular {
    public:
        using Type = typename decay<decltype(T::value)>::type;

        constexpr Modular() : value() {}
        template <typename U>
        Modular(const U& x) {
            value = normalize(x);
        }

        template <typename U>
        static Type normalize(const U& x) {
            Type v;
            if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
            else v = static_cast<Type>(x % mod());
            if (v < 0) v += mod();
            return v;
        }

        const Type& operator()() const { return value; }
        template <typename U>
        explicit operator U() const { return static_cast<U>(value); }
        constexpr static Type mod() { return T::value; }

        Modular& operator+=(const Modular& other) { value += other.value; value -= (value >= mod()) * mod(); return *this; }
        Modular& operator-=(const Modular& other) { value -= other.value; value += (value < 0) * mod(); return *this; }
        template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
        template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
        Modular& operator++() { return *this += 1; }
        Modular& operator--() { return *this -= 1; }
        Modular operator++(int) { Modular result(*this); *this += 1; return result; }
        Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
        Modular operator-() const { return Modular(-value); }

        template <typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
            value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
            return *this;
        }
        template <typename U = T>
        typename enable_if<is_same<typename Modular<U>::Type, int64_t>::value, Modular>::type& operator*=(const Modular& rhs) {
            int64_t q = int64_t(static_cast<long double>(value) * rhs.value / mod());
            value = normalize(value * rhs.value - q * mod());
            return *this;
        }
        template <typename U = T>
        typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
        value = normalize(value * rhs.value);
            return *this;
        }

        Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

        friend const Type& abs(const Modular& x) { return x.value; }

        template <typename U>
        friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

        template <typename U>
        friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

        template <typename V, typename U>
        friend V& operator>>(V& stream, Modular<U>& number);

    private:
        Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
    assert(b >= 0);
    Modular<T> x = a, res = 1;
    U p = b;
    while (p > 0) {
        if (p & 1) res *= x;
        x *= x;
        p >>= 1;
    }
    return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
    return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
    return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
    return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
    typename common_type<typename Modular<T>::Type, int64_t>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
}

// using ModType = int;

// struct VarMod { static ModType value; };
// ModType VarMod::value;
// ModType& md = VarMod::value;
// using Mint = Modular<VarMod>;

constexpr int md = MOD;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;

// vector<Mint> fact(1, 1);
// vector<Mint> inv_fact(1, 1);

// Mint C(int n, int k) {
//     if (k < 0 || k > n) {
//         return 0;
//     }
//     while ((int) fact.size() < n + 1) {
//         fact.push_back(fact.back() * (int) fact.size());
//         inv_fact.push_back(1 / fact.back());
//     }
//     return fact[n] * inv_fact[k] * inv_fact[n - k];
// }



//	https://github.com/the-tourist/algo/


struct Info {
    int len;
    vector<int> pos;
    vector<Mint> ans;
    Info(){
        len = 0;
        pos.assign(3,0);
        ans.assign(3,0);
    }

    Info(int val){
        len = 1;
        val--;
        ans.assign(3,1);
        ans[val] = 0;
        for(int i = 0; i < 3; i++){
            pos.push_back((6-i-val)%3);
        }
    }

    
    Info Unite(const Info& b) const {
        Info res;
        res.len = len + b.len;
        for(int i = 0; i < 3; i++){
            res.ans[i] = ans[b.pos[i]] + b.ans[i]*power(Mint(2),len);
            res.pos[i] = pos[b.pos[i]];
        }

        return res;
    }

    static Info GetDefault([[maybe_unused]] int l, [[maybe_unused]] int r) {
        return Info();
    }
};

	
//	https://github.com/the-tourist/algo/


namespace seg_tree {
	
	// Floor of log_2(a); index of highest 1-bit
	inline int floor_log_2(int a) {
	    return a ? bit_width(unsigned(a)) - 1 : -1;
	}
	
	struct point {
	    int a;
	    point() : a(0) {}
	    explicit point(int a_) : a(a_) { assert(a >= -1); }
	
	    explicit operator bool () { return bool(a); }
	
	    // This is useful so you can directly do array indices
	    /* implicit */ operator int() const { return a; }
	
	    point c(bool z) const {
	        return point((a << 1) | z);
	    }
	
	    point operator [] (bool z) const {
	        return c(z);
	    }
	
	    point p() const {
	        return point(a >> 1);
	    }
	
	    friend std::ostream& operator << (std::ostream& o, const point& p) { return o << int(p); }
	
	    template <typename F> void for_each(F f) const {
	        for (int v = a; v > 0; v >>= 1) {
	            f(point(v));
	        }
	    }
	
	    template <typename F> void for_parents_down(F f) const {
	        // strictly greater than 0
	        for (int L = floor_log_2(a); L > 0; L--) {
	            f(point(a >> L));
	        }
	    }
	
	    template <typename F> void for_parents_up(F f) const {
	        for (int v = a >> 1; v > 0; v >>= 1) {
	            f(point(v));
	        }
	    }
	
	    point& operator ++ () { ++a; return *this; }
	    point operator ++ (int) { return point(a++); }
	    point& operator -- () { --a; return *this; }
	    point operator -- (int) { return point(a--); }
	};
	
	struct range {
	    int a, b;
	    range() : a(1), b(1) {}
	    range(int a_, int b_) : a(a_), b(b_) {
	        assert(1 <= a && a <= b && b <= 2 * a);
	    }
	    explicit range(std::array<int, 2> r) : range(r[0], r[1]) {}
	
	    explicit operator std::array<int, 2>() const {
	        return {a, b};
	    }
	
	    const int& operator[] (bool z) const {
	        return z ? b : a;
	    }
	
	    friend std::ostream& operator << (std::ostream& o, const range& r) { return o << "[" << r.a << ".." << r.b << ")"; }
	
	    // Iterate over the range from outside-in.
	    //   Calls f(point a)
	    template <typename F> void for_each(F f) const {
	        for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
	            if (x & 1) f(point(x++));
	            if (y & 1) f(point(--y));
	        }
	    }
	
	    // Iterate over the range from outside-in.
	    //   Calls f(point a, bool is_right)
	    template <typename F> void for_each_with_side(F f) const {
	        for (int x = a, y = b; x < y; x >>= 1, y >>= 1) {
	            if (x & 1) f(point(x++), false);
	            if (y & 1) f(point(--y), true);
	        }
	    }
	
	    // Iterate over the range from left to right.
	    //    Calls f(point)
	    template <typename F> void for_each_l_to_r(F f) const {
	        int anc_depth = floor_log_2((a - 1) ^ b);
	        int anc_msk = (1 << anc_depth) - 1;
	        for (int v = (-a) & anc_msk; v; v &= v - 1) {
	            int i = countr_zero(unsigned(v));
	            f(point(((a - 1) >> i) + 1));
	        }
	        for (int v = b & anc_msk; v; ) {
	            int i = floor_log_2(v);
	            f(point((b >> i) - 1));
	            v ^= (1 << i);
	        }
	    }
	
	    // Iterate over the range from right to left.
	    //    Calls f(point)
	    template <typename F> void for_each_r_to_l(F f) const {
	        int anc_depth = floor_log_2((a - 1) ^ b);
	        int anc_msk = (1 << anc_depth) - 1;
	        for (int v = b & anc_msk; v; v &= v - 1) {
	            int i = countr_zero(unsigned(v));
	            f(point((b >> i) - 1));
	        }
	        for (int v = (-a) & anc_msk; v; ) {
	            int i = floor_log_2(v);
	            f(point(((a - 1) >> i) + 1));
	            v ^= (1 << i);
	        }
	    }
	
	    template <typename F> void for_parents_down(F f) const {
	        int x = a, y = b;
	        if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
	        int dx = countr_zero(unsigned(x));
	        int dy = countr_zero(unsigned(y));
	        int anc_depth = floor_log_2((x - 1) ^ y);
	        for (int i = floor_log_2(x); i > dx; i--) {
	            f(point(x >> i));
	        }
	        for (int i = anc_depth; i > dy; i--) {
	            f(point(y >> i));
	        }
	    }
	
	    template <typename F> void for_parents_up(F f) const {
	        int x = a, y = b;
	        if ((x ^ y) > x) { x <<= 1, std::swap(x, y); }
	        int dx = countr_zero(unsigned(x));
	        int dy = countr_zero(unsigned(y));
	        int anc_depth = floor_log_2((x - 1) ^ y);
	        for (int i = dx + 1; i <= anc_depth; i++) {
	            f(point(x >> i));
	        }
	        for (int v = y >> (dy + 1); v; v >>= 1) {
	            f(point(v));
	        }
	    }
	};
	
	struct in_order_layout {
	    // Alias them in for convenience
	    using point = seg_tree::point;
	    using range = seg_tree::range;
	
	    int n, s;
	    in_order_layout() : n(0), s(0) {}
	    in_order_layout(int n_) : n(n_), s(n ? bit_ceil(unsigned(n)) : 0) {}
	
	    point get_point(int a) const {
	        assert(0 <= a && a < n);
	        a += s;
	        return point(a >= 2 * n ? a - n : a);
	    }
	
	    range get_range(int a, int b) const {
	        assert(0 <= a && a <= b && b <= n);
	        if (n == 0) return range();
	        a += s, b += s;
	        return range((a >= 2 * n ? 2 * (a - n) : a), (b >= 2 * n ? 2 * (b - n) : b));
	    }
	
	    range get_range(std::array<int, 2> p) const {
	        return get_range(p[0], p[1]);
	    }
	
	    int get_leaf_index(point pt) const {
	        int a = int(pt);
	        assert(n <= a && a < 2 * n);
	        return (a < s ? a + n : a) - s;
	    }
	
	    std::array<int, 2> get_node_bounds(point pt) const {
	        int a = int(pt);
	        assert(1 <= a && a < 2 * n);
	        int l = countl_zero(unsigned(a)) - countl_zero(unsigned(2 * n - 1));
	        int x = a << l, y = (a + 1) << l;
	        assert(s <= x && x < y && y <= 2 * s);
	        return {(x >= 2 * n ? (x >> 1) + n : x) - s, (y >= 2 * n ? (y >> 1) + n : y) - s};
	    }
	
	    int get_node_split(point pt) const {
	        int a = int(pt);
	        assert(1 <= a && a < n);
	        int l = countl_zero(unsigned(2 * a + 1)) - countl_zero(unsigned(2 * n - 1));
	        int x = (2 * a + 1) << l;
	        assert(s <= x && x < 2 * s);
	        return (x >= 2 * n ? (x >> 1) + n : x) - s;
	    }
	
	    int get_node_size(point pt) const {
	        auto bounds = get_node_bounds(pt);
	        return bounds[1] - bounds[0];
	    }
	};
	
	struct circular_layout {
	    // Alias them in for convenience
	    using point = seg_tree::point;
	    using range = seg_tree::range;
	
	    int n;
	    circular_layout() : n(0) {}
	    circular_layout(int n_) : n(n_) {}
	
	    point get_point(int a) const {
	        assert(0 <= a && a < n);
	        return point(n + a);
	    }
	
	    range get_range(int a, int b) const {
	        assert(0 <= a && a <= b && b <= n);
	        if (n == 0) return range();
	        return range(n + a, n + b);
	    }
	
	    range get_range(std::array<int, 2> p) const {
	        return get_range(p[0], p[1]);
	    }
	
	    int get_leaf_index(point pt) const {
	        int a = int(pt);
	        assert(n <= a && a < 2 * n);
	        return a - n;
	    }
	
	    // Returns {x,y} so that 0 <= x < n and 1 <= y <= n
	    // If the point is non-wrapping, then 0 <= x < y <= n
	    std::array<int, 2> get_node_bounds(point pt) const {
	        int a = int(pt);
	        assert(1 <= a && a < 2 * n);
	        int l = countl_zero(unsigned(a)) - countl_zero(unsigned(2 * n - 1));
	        int s = bit_ceil(unsigned(n));
	        int x = a << l, y = (a + 1) << l;
	        assert(s <= x && x < y && y <= 2 * s);
	        return {(x >= 2 * n ? x >> 1 : x) - n, (y > 2 * n ? y >> 1 : y) - n};
	    }
	
	    // Returns the split point of the node, such that 1 <= s <= n.
	    int get_node_split(point pt) const {
	        int a = int(pt);
	        assert(1 <= a && a < n);
	        return get_node_bounds(pt.c(0))[1];
	    }
	
	    int get_node_size(point pt) const {
	        auto bounds = get_node_bounds(pt);
	        int r = bounds[1] - bounds[0];
	        return r > 0 ? r : r + n;
	    }
	};
	
} // namespace seg_tree
	
	

//	https://github.com/the-tourist/algo/


template <typename Info>
class SimpleSegmentTree {
    public:
        int n;
        vector<Info> infos;
        seg_tree::in_order_layout layout;

        void UpdateNode(seg_tree::point a) {
            infos[a] = infos[a.c(0)].Unite(infos[a.c(1)]);
        } 
  
        SimpleSegmentTree(int n_) : SimpleSegmentTree(vector<Info>(n_)) {}

        SimpleSegmentTree(const vector<Info>& a) : n(int(a.size())) {
            assert(n > 0);
            infos.resize(2 * n);
            layout = seg_tree::in_order_layout(n);
            for (int i = 0; i < n; i++) {
                infos[layout.get_point(i)] = a[i];
            }
            for (int i = n - 1; i >= 1; i--) {
                infos[i] = infos[2 * i].Unite(infos[2 * i + 1]);
            }
        }

        void Set(int p, const Info& v) {
            auto pt = layout.get_point(p);
            infos[pt] = v;
            pt.for_parents_up([&](seg_tree::point a) {
                UpdateNode(a);
            });
        }

        Info Query(int l, int r) {
            auto rng = layout.get_range(l, r);
            Info res;
            rng.for_each_l_to_r([&](seg_tree::point a) {
                res = res.Unite(infos[a]);
            });
            return res;
        }

        Info Get(int p) {
            auto pt = layout.get_point(p);
            return infos[pt];
        }

        template<typename F>
        int MaxRight(int l, F f) {
            auto rng = layout.get_range(l, n);
            int res = n;
            Info sum;
            rng.for_each_l_to_r([&](seg_tree::point a) {
                if (res != n) {
                    return;
                }
                auto new_sum = sum.Unite(infos[a]);
                if (f(new_sum)) {
                    sum = new_sum;
                    return;
                }
                while (a < n) {
                    new_sum = sum.Unite(infos[a.c(0)]);
                    if (f(new_sum)) {
                        sum = new_sum;
                        a = a.c(1);
                    } else {
                        a = a.c(0);
                    }
                }
                res = layout.get_node_bounds(a)[0];
            });
            return res;
        }

        template<typename F>
        int MinLeft(int r, F f) {
            auto rng = layout.get_range(0, r);
            int res = 0;
            Info sum;
            rng.for_each_r_to_l([&](seg_tree::point a) {
                if (res != 0) {
                    return;
                }
                auto new_sum = infos[a].Unite(sum);
                if (f(new_sum)) {
                    sum = new_sum;
                    return;
                }
                while (a < n) {
                    new_sum = infos[a.c(1)].Unite(sum);
                    if (f(new_sum)) {
                        sum = new_sum;
                        a = a.c(0);
                    } else {
                        a = a.c(1);
                    }
                }

                res = layout.get_node_bounds(a)[1];
            });
            return res;
        }
};


int n,q;
vector<Info> arr;

void solve(){
    cin >> n >> q;
    arr.assign(n,Info(1));
    int t;

    for(int i = 0; i < n; i++){
        cin >> t; arr[i] = Info(t);
    }
    for(auto i:arr){
        dbg(i.ans);
        dbg(i.pos);
        dbg(i.len);
    }

    SimpleSegmentTree<Info> seg(arr);
    char s;
    int x,y;
    while(q--){
        cin >> s >> x >> y;
        x--;
        if(s == 's'){
            cout << seg.Query(x,y).ans[0] << nl;
        }else{
            seg.Set(x,Info(y));
        }
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2073/problem/D
