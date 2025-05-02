//  Salt air, and the rust on your door
//  I never needed anything more
//  Whispers of "Are you sure?"
//  "Never have I have before"

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
vector<int> a;
vector<int> b;

void solve(){
    cin >> n;
    a.assign(n,0);
    b.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i++){
        cin >> b[i];
    }

    int c = -1;
    map<int,pair<int,int>> mp;
    vector<pair<int,int>> v;

    for(int i = 0; i < n; i++){
        if(a[i] == b[i] && c == -1){
            c = i+1;
        }else if(a[i] == b[i]){
            cout << "-1" << nl; return;
        }else if(mp.count(b[i])){
            if(a[i]!=mp[b[i]].first){
                cout << "-1" << nl; return;
            }
            v.push_back({i+1,mp[b[i]].second});
        }else{
            mp[a[i]] = {b[i],i+1};
            mp[b[i]] = {a[i],i+1};
        }
    }
    assert(v.size() == n/2);
    vector<pair<int,int>> ans;
    int l = 1, r = n;
    vector<int> mp2(n+1,0);
    vector<int> mp3(n+1,0);
    for(int i = 1; i <= n; i++){
        mp2[i] = i;
        mp3[i] = i;
    }
    for(auto i:v){
        if(l != mp2[i.first]){
            ans.push_back({l,mp2[i.first]});
            swap(mp2[mp3[l]],mp2[i.first]);
            swap(mp3[l],mp3[mp2[mp3[l]]]);
        }
        if(r != mp2[i.second]){
            ans.push_back({r,mp2[i.second]});
            swap(mp2[mp3[r]],mp2[i.second]);
            swap(mp3[r],mp3[mp2[mp3[r]]]);
        }
        l++;
        r--;
    }
    dbg(c);
    dbg(mp2);
    // if(c!=-1)   assert(c==mp2[n/2+1+1]);
    // if(c != -1){
        // assert(mp2[c]==l);
    // }
    cout << ans.size() << nl;
    for(auto i:ans){
        cout << i.first << " " << i.second << nl;
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
// problem-url: https://codeforces.com/contest/2084/problem/C
