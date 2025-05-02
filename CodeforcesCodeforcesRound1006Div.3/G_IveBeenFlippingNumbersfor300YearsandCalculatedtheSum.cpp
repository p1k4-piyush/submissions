//  Their parties were tasteful if a little loud
//  The doctor had told him to settle down
//  It must have been her faunt his heart gave out

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


// const int MOD = 998244353;
const int MOD = 1000000007;


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


ll n,k;

void solve(){
    cin >> n >> k;
    Mint ans = 0;
    ll sq = ll(sqrt(n));
    for(int i = 2; i <= min(sq,k); i++){
        ll t = n;
        vector<ll> tt;
        while(t > 0){
            tt.push_back(t%i);
            t /= i;
        }
        t = 0;
        for(auto j:tt){
            t *= i;
            t += j;
        }
        ans += t;
    }
    
    if(k > sq){
        ll l = sq+1, r = min(k,n);
        ans += Mint(n)*((Mint(r)*Mint(r+1)/Mint(2))-(Mint(l-1)*Mint(l)/Mint(2)));
        ll L = l;
        while(L <= r){
            ll t = n/L;
            ll R = min(n/t,r);

            ans -= Mint(t)*((Mint(R)*Mint(R+1)*Mint(2*R+1)/Mint(6))-(Mint(L-1)*Mint(L)*Mint(2*L-1)/Mint(6)));
            ans += Mint(t)*Mint(R-L+1);

            L = R+1;
        }
    } 
    ans += Mint(max(k-n,ll(0)))*Mint(n);


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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2072/problem/G
