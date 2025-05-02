//  I can see you starin', honey
//  Like he's just your understudy
//  Like you'd get your knuckles bloody for me

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,k;
vector<int> arr;
vector<int> pre;
vector<int> suf;

void solve(){
    cin >> n >> k;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    if (k == 1){
        cout << max(arr[n-1] + *max_element(arr.begin(),arr.end()-1),arr[0]+ *max_element(arr.begin()+1,arr.end())) << nl; 
        return;
    }

    sort(all(arr),greater<int>());
    cout << accumulate(arr.begin(),arr.begin()+k+1,0ll) << nl;
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
// problem-url: https://codeforces.com/contest/2075/problem/B
