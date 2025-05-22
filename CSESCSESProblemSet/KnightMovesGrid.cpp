//  They say she was seen on occasion
//  Pacing the rocks staring out at the midnight sea
//  And in a feud with her neighbor
//  She stole his dog and dyed it key lime green

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
vector<vector<int>> arr;
vector<pair<int,int>> dirs = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

void solve(){
    cin >> n;
    arr.assign(n,vector<int>(n,-1));
    
    // priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> q;
    queue<tuple<int,int,int>> q;
    q.push({0,0,0});

    while(!q.empty()){
        auto t = q.front();
        q.pop();
        if(arr[get<1>(t)][get<2>(t)] != -1){
            continue;
        }
        arr[get<1>(t)][get<2>(t)] = get<0>(t);
        for(auto i:dirs){
            int x = get<1>(t) + i.first;
            int y = get<2>(t) + i.second;
            if (x < 0 || x >= n || y < 0 || y >= n || arr[x][y] != -1){
                continue;
            }
            q.push({get<0>(t)+1,x,y});
        }
    }
    dbg(arr);
    for(auto i:arr){
        for(auto j:i){
            cout << j << " ";
        }
        cout << nl;
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


// time-limit: 1000
// problem-url: https://cses.fi/problemset/task/3217
