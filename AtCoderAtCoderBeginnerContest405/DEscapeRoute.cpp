//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'

#include <bits/stdc++.h>
#include <utility>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

int h,w;
vector<vector<char>> arr;
vector<vector<int>> dist;
vector<pair<pair<int,int>, char>> dir = {{{1,0},'^'},{{0,1},'<'},{{-1,0},'v'},{{0,-1},'>'}};


void solve(){
    cin >> h >> w;
    arr.assign(h,vector<char>(w,'0'));
    dist.assign(h,vector<int>(w,INT_MAX));

    vector<pair<int,int>> starts;
    char t;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 'E'){
                starts.push_back({i,j});
            }
        }
    }

    priority_queue<pair<pair<int,pair<int,int>>,char>,vector<pair<pair<int,pair<int,int>>,char>>,greater<pair<pair<int,pair<int,int>>,char>>> pq; 
    for(auto i:starts){
        pq.push({{0,i},'E'});
    }
    int c = 0;

    while(c < h*w && !pq.empty()){
        int d = pq.top().first.first;
        pair<int,int> cur = pq.top().first.second;
        char tt = pq.top().second;
        if(arr[cur.first][cur.second] == '#'){
            pq.pop();
            continue;
        }
        if (dist[cur.first][cur.second]>d){
            arr[cur.first][cur.second] = tt;
            dist[cur.first][cur.second] = d;
            for(auto i:dir){
                pair<int,int> p = {cur.first+i.first.first,cur.second+i.first.second}; 
                if (p.first >= 0 && p.first < h && p.second >= 0 && p.second < w){
                    pq.push({{d+1,p},i.second});
                }
            }
        }
        pq.pop();
    }
    
    
    
    for(auto i:arr){
        for(auto j:i){
            cout << j;
        }
        cout << nl;
    }
    cout << nl;
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
// problem-url: https://atcoder.jp/contests/abc405/tasks/abc405_d
