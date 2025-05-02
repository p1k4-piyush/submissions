//  Even on my worst day, did I deserve, babe
//  All the hell you gave me?
//  'Cause I loved you, swear I loved you
//  'Til my dying day

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")



#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

//	https://github.com/the-tourist/algo/


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<long long, vector<int>, custom_hash> safe_map;


// #include <ext/pb_ds/assoc_container.hpp>

// template <typename K, typename V, typename Hash = splitmix64_hash>
// using HashMap = __gnu_pbds::gp_hash_table<K, V, Hash>;

// template <typename K, typename Hash = splitmix64_hash>
// using HashSet = HashMap<K, __gnu_pbds::null_type, Hash>;



//	https://github.com/the-tourist/algo/


const int MOD = 998244353;

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


namespace factorizer {

    template <typename T>
    struct FactorizerVarMod { static T value; };
    template <typename T>
    T FactorizerVarMod<T>::value;

    template <typename T>
    bool IsPrime(T n, const vector<T>& bases) {
        if (n < 2) {
            return false;
        }
        vector<T> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (const T& x : small_primes) {
            if (n % x == 0) {
                return n == x;
            }
        }
        if (n < 31 * 31) {
            return true;
        }
        int s = 0;
        T d = n - 1;
        while ((d & 1) == 0) {
            d >>= 1;
            s++;
        }
        FactorizerVarMod<T>::value = n;
        for (const T& a : bases) {
            if (a % n == 0) {
                continue;
            }
            Modular<FactorizerVarMod<T>> cur = a;
            cur = power(cur, d);
            if (cur == 1) {
                continue;
            }
            bool witness = true;
            for (int r = 0; r < s; r++) {
                if (cur == n - 1) {
                    witness = false;
                    break;
                }
                cur *= cur;
            }
            if (witness) {
                return false;
            }   
        }
        return true;
    }

    bool IsPrime(int64_t n) {
        return IsPrime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
    }

    bool IsPrime(int32_t n) {
        return IsPrime(n, {2, 7, 61});
    }

    // but if you really need uint64_t version...
    /*
    bool IsPrime(uint64_t n) {
        if (n < 2) {
            return false;
        }
        vector<uint32_t> small_primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        for (uint32_t x : small_primes) {
            if (n == x) {
                return true;
            }
            if (n % x == 0) {
                return false;
            }
        }
        if (n < 31 * 31) {
            return true;
        }
        uint32_t s = __builtin_ctzll(n - 1);
        uint64_t d = (n - 1) >> s;
        function<bool(uint64_t)> witness = [&n, &s, &d](uint64_t a) {
            uint64_t cur = 1, p = d;
            while (p > 0) {
                if (p & 1) {
                    cur = (__uint128_t) cur * a % n;
                }
                a = (__uint128_t) a * a % n;
                p >>= 1;
            }
            if (cur == 1) {
                return false;
            }
            for (uint32_t r = 0; r < s; r++) {
                if (cur == n - 1) {
                    return false;
                }
                cur = (__uint128_t) cur * cur % n;
            }
            return true;
        };
        vector<uint64_t> bases_64bit = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
        for (uint64_t a : bases_64bit) {
            if (a % n == 0) {
                return true;
            }
            if (witness(a)) {
                return false;
            }
        }
        return true;
    }
    */

    vector<int> least = {0, 1};
    vector<int> primes;
    int precalculated = 1;

    void RunLinearSieve(int n) {
        n = max(n, 1);
        least.assign(n + 1, 0);
        primes.clear();
        for (int i = 2; i <= n; i++) {
            if (least[i] == 0) {
                least[i] = i;
              primes.push_back(i);
            }
            for (int x : primes) {
                if (x > least[i] || i * x > n) {
                    break;
                }
                least[i * x] = x;
            }
        }
        precalculated = n;
    }

    void RunSlowSieve(int n) {
        n = max(n, 1);
        least.assign(n + 1, 0);
        for (int i = 2; i * i <= n; i++) {
            if (least[i] == 0) {
                for (int j = i * i; j <= n; j += i) {
                    if (least[j] == 0) {
                        least[j] = i;
                    }
                }
            }
        }
        primes.clear();
        for (int i = 2; i <= n; i++) {
            if (least[i] == 0) {
                least[i] = i;
                primes.push_back(i);
            }
        }
        precalculated = n;
    }

    void RunSieve(int n) {
        RunLinearSieve(n);
    }   

    template <typename T>
    vector<pair<T, int>> MergeFactors(const vector<pair<T, int>>& a, const vector<pair<T, int>>& b) {
        vector<pair<T, int>> c;
        int i = 0;
        int j = 0;
        while (i < (int) a.size() || j < (int) b.size()) {
            if (i < (int) a.size() && j < (int) b.size() && a[i].first == b[j].first) {
                c.emplace_back(a[i].first, a[i].second + b[j].second);
                ++i;
                ++j;
                continue;
            }
            if (j == (int) b.size() || (i < (int) a.size() && a[i].first < b[j].first)) {
                c.push_back(a[i++]);
            } else {
                c.push_back(b[j++]);
            }
        }
        return c;
    }

    template <typename T>
    vector<pair<T, int>> RhoC(const T& n, const T& c) {
        if (n <= 1) {
            return {};
        }
        if ((n & 1) == 0) {
            return MergeFactors({{2, 1}}, RhoC(n / 2, c));
        }
        if (IsPrime(n)) {
            return {{n, 1}};
        }
        FactorizerVarMod<T>::value = n;
        Modular<FactorizerVarMod<T>> x = 2;
        Modular<FactorizerVarMod<T>> saved = 2;
        T power = 1;
        T lam = 1;
        while (true) {
            x = x * x + c;
            T g = gcd((x - saved)(), n);
            if (g != 1) {
                return MergeFactors(RhoC(g, c + 1), RhoC(n / g, c + 1));
            }
            if (power == lam) {
                saved = x;
                power <<= 1;
                lam = 0;
            }
            lam++;
        }
        return {};
    }

    template <typename T>
    vector<pair<T, int>> Rho(const T& n) {
        return RhoC(n, static_cast<T>(1));
    }

    template <typename T>
    vector<pair<T, int>> Factorize(T x) {
        if (x <= 1) {
            return {};
        }
        if (x <= precalculated) {
            vector<pair<T, int>> ret;
            while (x > 1) {
                if (!ret.empty() && ret.back().first == least[x]) {
                    ret.back().second++;
                } else {
                    ret.emplace_back(least[x], 1);
                }
                x /= least[x];
            }
            return ret;
        }
    
        if (x <= static_cast<int64_t>(precalculated) * precalculated) {
            vector<pair<T, int>> ret;
            if (!IsPrime(x)) {
                for (T i : primes) {
                    T t = x / i;
                    if (i > t) {
                        break;
                    }
                    if (x == t * i) {
                        int cnt = 0;
                        while (x % i == 0) {
                            x /= i;
                            cnt++;
                        }
                        ret.emplace_back(i, cnt);
                        if (IsPrime(x)) {
                            break;
                        }
                    }
                }
            }
            if (x > 1) {
                ret.emplace_back(x, 1);
            }
            return ret;
        }
        return Rho(x);
    }

    template <typename T>
    vector<T> BuildDivisorsFromFactors(const vector<pair<T, int>>& factors) {
        vector<T> divisors = {1};
        for (auto& p : factors) {
            int sz = (int) divisors.size();
            for (int i = 0; i < sz; i++) {
                T cur = divisors[i];
                for (int j = 0; j < p.second; j++) {
                    cur *= p.first;
                    divisors.push_back(cur);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        return divisors;
    }

}  // namespace factorizer



const int MAX_N = 1e5+100;
int n,q;
vector<vector<int>> arr;

void solve(){
    cin >> n >> q;
    safe_map mp;
    vector<int> arr(n,0);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]].push_back(i+1);
    }

    vector<tuple<int,int,int,int>> queries(q,{0,0,0,0});
    int c = 0;
    for(auto&[l,r,k,i]:queries){
        cin >> k >> l >> r;
        i = c++;
    }
    
    vector<ll> vans(q,ll(0));

    sort(queries.begin(),queries.end());
    dbg(queries);
    
    for(auto [l,r,k,idx]:queries){
        vector<int> factors = factorizer::BuildDivisorsFromFactors(factorizer::Factorize(k));
        vector<int> v;
        for(auto i:factors){
            if (i == 1) continue;

            if(mp[i].size() == 0) continue;
            auto tt = lower_bound(mp[i].begin(),mp[i].end(),l);
            if (tt==mp[i].end()){
                continue;
            }
            if(*tt > r) continue;
            v.push_back(*tt);
        }
        sort(v.begin(),v.end());
        dbg(v);

        int p = l;
        ll ans = 0;
        for(auto i:v){
            int c = i - p;
            ans += ll(k)*ll(c);
            while(k%arr[i-1] == 0) k/= arr[i-1];
            p = i;
        }
        ans += ll(r-p+1)*ll(k);
        vans[idx] = ans;
    }
    for(auto i:vans){
        cout << i << nl;
    }

    // cout << nl;
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


// time-limit: 4000
// problem-url: https://codeforces.com/problemset/problem/2094/H
