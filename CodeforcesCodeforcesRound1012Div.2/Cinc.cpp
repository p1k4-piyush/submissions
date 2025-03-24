//  Second, third, and hundreth chances
//  Balancin' on breaking branches
//  Those eyes add insult to injury


#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

int n;
vector<pair<int,int>> ans;
void solve(){
    cin >> n;
    ans.assign(n,{0,0});


    set<pair<int,int>> s1,s2;
    s1.insert({1,1});
    s2.insert({1,1});
    set<pair<int,int>> occ;
    bool t;
    ll c1 = 1, c2 = 1;
    for(int i = 0; i < n; i++){
        while (s1.empty()){
            c1++;
            for(int i = 0; i <= c1; i++){
                if ((i%3) && ((c1-i)%3)){
                    if ((i%3 == 2)&&((c1-i)%3 == 2)) continue;
                    if ((i%3 == 2)&&((c1-i)%3 == 1)){
                        if (c1-i >= 2 && !(occ.count({i,c1-i}))){
                            s1.insert({i,c1-i});
                        }
                    }
                    if (occ.count({i,c1-i})) continue;
                    s1.insert({i,c1-i});
                }
            }
        }
        while (s2.empty()){
            c2++;
            for(int i = 0; i <= c2; i++){
                if ((i%3 == 1) && ((c2-i)%3 == 1)){
                    if (occ.count({i,c2-i})) continue;
                    s2.insert({i,c2-i});
                }
            }
        }
        // dbg(s1);
        // dbg(s2);
        cin >> t;
        if (!t){
            ans[i] = *s2.begin();
            occ.insert(*s2.begin());
            s1.erase(*s2.begin());
            s2.erase(s2.begin());

        }else{
            ans[i] = *s1.begin();
            occ.insert(*s1.begin());
            s2.erase(*s1.begin());
            s1.erase(s1.begin());
        }
    }
    
    
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
// problem-url: https://codeforces.com/contest/2090/problem/C


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2090/problem/C
