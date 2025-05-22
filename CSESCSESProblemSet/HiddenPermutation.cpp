//  Time, mystical time
//  Cuttin' me open then healing me fine
//  Were there clues I didn't see?

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
vector<int> arr;


bool cus(int a,int b){
    cout << "? " << a << " " << b << nl;
    cout.flush();
    string t;
    cin >> t;
    if(t == "YES"){
        return true;
    }else{
        return false;
    }
}

void solve(){
    cin >> n;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        arr[i] = i+1;
    }
    stable_sort(arr.begin(),arr.end(),cus);
    
    vector<int> ans(n,0);
    for(int i = 0; i < n; i++){
        ans[arr[i]-1] = i+1;
    }

    cout << "! ";
    for(auto i:ans){
        cout << i << " ";
    }
    
    cout << nl;
    cout.flush();
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
// problem-url: https://cses.fi/problemset/task/3139
