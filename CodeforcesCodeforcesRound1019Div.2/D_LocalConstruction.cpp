//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'

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

int n;
vector<int> arr;
vector<int> ans;
void solve(){
    cin >> n;
    vector<vector<int>> a(n+1,vector<int>());
    arr.assign(n,0);
    ans.assign(n,-1);
    int fi,li;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] == -1){
            ans[i] = 0;
            fi = i;
            li = i;
            continue;
        }
        a[arr[i]].push_back(i);
    }

    int mn = 0, mx = 0;
    
    for(int i = n; i >= 0; i--){
        if(i&1){
            auto t = lower_bound(a[i].begin(),a[i].end(),li);
            int c = a[i].size();
            if(t != a[i].end()){
                c = t-a[i].begin();
            }
            int c1 = c;
            while(c1 < a[i].size()){
                mx++;
                li = a[i][c1];
                ans[a[i][c1++]] = mx;
            }
            c1 = c-1;
            while(c1 >= 0){
                mx++;
                ans[a[i][c1--]]=mx;
            }
        }else{
            auto t = lower_bound(a[i].begin(),a[i].end(),li);
            int c = a[i].size();
            if(t != a[i].end()){
                c = t-a[i].begin();
            }
            int c1 = c;
            while(c1 < a[i].size()){
                mn--;
                li = a[i][c1];
                ans[a[i][c1++]] = mn;
            }
            c1 = c-1;
            while(c1 >= 0){
                mn--;
                ans[a[i][c1--]]=mn;
            }
        }
    }

    for(auto i:ans){
        cout << i-mn+1 << " ";
    }
    

    cout << nl;
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
// problem-url: https://codeforces.com/contest/2103/problem/D
