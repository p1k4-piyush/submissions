//  We gather here, we line up, weepin' in a sunlit room
//  And if I'm on fire, you'll be made of ashes tooi

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
//	https://github.com/p1k4-piyush/templates/


template<typename T>
int lis(const vector<T>& a) {
    vector<T> u;
    for (const T& x : a) {
        auto it = lower_bound(u.begin(), u.end(), x);
        if (it == u.end()) {
            u.push_back(x);
        } else {
            *it = x;
        };
    };
    return (int) u.size();
};



int n;
vector<int> arr;

void solve(){
    cin >> n;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    
    cout << lis(arr) << nl;
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/1145
