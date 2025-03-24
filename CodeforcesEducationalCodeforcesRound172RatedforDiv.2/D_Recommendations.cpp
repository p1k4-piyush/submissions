//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I

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
int n;
vector<pair<pair<int,int>,int>> arr;
vector<int> ans;

void solve(){
    cin >> n;
    arr.assign(n,{{0,0},0});
    ans.assign(n,0);

    for(int i = 0; i < n; i++){
        cin >> arr[i].first.first >> arr[i].first.second;
        arr[i].second = i;
    }

    sort(all(arr),[&](pair<pair<int,int>,int> i, pair<pair<int,int>,int> j){
        if (i.first.first!=j.first.first){
            return i.first.first < j.first.first;
        }
        return i.first.second > j.first.second;
    });

    set<int> s;
    for(auto &i:arr){
        auto tt = s.lower_bound(i.first.second);
        if (tt != s.end()){
            ans[i.second]+= *tt-i.first.second;
        }
        s.insert(i.first.second);
        i.first.first = -i.first.first;
        i.first.second = -i.first.second;
        swap(i.first.first,i.first.second);
    }

    sort(all(arr),[&](pair<pair<int,int>,int> i, pair<pair<int,int>,int> j){
        if (i.first.first!=j.first.first){
            return i.first.first < j.first.first;
        }
        return i.first.second > j.first.second;
    });
    s.clear();
    for(auto &i:arr){
        auto tt = s.lower_bound(i.first.second);
        if (tt != s.end()){
            ans[i.second]+= *tt-i.first.second;
        }
        s.insert(i.first.second);
    }
    int t = 0;
    while(t < n-1){
        int tt = t;
        while(t < n-1 && arr[t].first == arr[t+1].first){
            t++;
        }
        if (t != tt){
            for (int i = tt; i <= t; i++){
                ans[arr[i].second]=0;
            }
        }
        t++;
    }

    for(auto i:ans){
        cout << i << nl;
    }
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
// problem-url: https://codeforces.com/problemset/problem/2042/D
