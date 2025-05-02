//  I think I've seen this film before
//  And I didn't like the ending 
//  You're not my homeland anymore
//  So what am I defending now?



#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int n,r,c;
string arr;
vector<int> ans;

void solve(){
    cin >> n >> r >> c;
    cin >> arr; 
    ans.assign(n,0);

    set<pair<int,int>> s;
    int x = 0, y = 0;

    s.insert({0,0});

    for(int i = 0; i < n; i++){
        if (arr[i] == 'N'){
            x--;
        }
        if (arr[i] == 'E'){
            y++;
        }
        if (arr[i] == 'W'){
            y--;
        }
        if (arr[i] == 'S'){
            x++;
        }

        if(s.count({x-r,y-c})){
            ans[i] = 1;
        }
        dbg(s);
        s.insert({x,y});
    }
    

    for(auto i:ans){
        cout << i;
    }
    
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
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_d


// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_d
