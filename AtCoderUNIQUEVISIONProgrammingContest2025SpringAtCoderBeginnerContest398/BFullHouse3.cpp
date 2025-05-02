//  And when I felt like I was an old cardigan
//  Under someone's bed
//  You put me on and said I was your favorite


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
int n;
vector<int> arr;

void solve(){
    n = 7;
    arr.assign(13,0);
    int t;
    for(int i = 0; i < n; i++){
        cin >> t;
        arr[t-1]++;
    }
    bool c1 = 0; bool c2 = 0;
    for (int i = 0; i < 13;i++){
        if (arr[i] == 2){
            c1 = 1; 
            if(c2){
                cout << "Yes"; return;
            }
            continue;
        }
        if (arr[i] < 2) continue;
        if (c1||c2){
            cout << "Yes"; return;
        }
        c2 = 1;
    }
    
    
    cout << "No";
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
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_b

// time-limit: 2000
// problem-url: https://atcoder.jp/contests/abc398/tasks/abc398_b
