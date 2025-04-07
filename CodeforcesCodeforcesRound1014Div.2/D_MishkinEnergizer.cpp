//  I didn't have it in myself to go with grace
//  And you're the hero flying around, saving face
//  And if I'm dead to you, why are you at the wake?

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

void solve(){

    cin >> n;
    
    string s;
    cin >> s;
    
    vector<int> ans;
    char ii = 'I', ll = 'L', tt = 'T'; 
    while(true){
        int i = 0, l = 0, t = 0;
    
        for(auto j:s){
            if (j == ii){
                i++;
            }else if(j == ll){
                l++;
            }else{
                t++;
            }
        }
        
        if (i == l && l == t){
            break;
        }
        
        if (i > l){
            swap(i,l);
            swap(ii,ll);
        }
        
        if (i > t){
            swap(i,t);
            swap(ii,tt);
        }
        
        if (l > t){
            swap(t,l);
            swap(ll,tt);
        }
 
        dbg(s);
        bool c = 0;
        
        for(int j = 1; j < s.size(); j++){
            if ((s[j]==ll||s[j-1]==ll)&&(s[j]==tt||s[j-1]==tt)){
                ans.push_back(j);
                s = s.substr(0,j)+ii+s.substr(j);
                c = 1;
                break;
            }
        }

        if (c) continue;

        for(int j = 1; j < s.size(); j++){
            if ((s[j]==ii||s[j-1]==ii)&&(s[j]==tt||s[j-1]==tt)){
                ans.push_back(j);
                s = s.substr(0,j)+ll+s.substr(j);
                c = 1;
                break;
            }
        }

        if (c) continue;

        for(int j = 1; j < s.size(); j++){
            if ((s[j]==ll||s[j-1]==ll)&&(s[j]==ii||s[j-1]==ii)){
                ans.push_back(j);
                s = s.substr(0,j)+tt+s.substr(j);
                c = 1;
                break;
            }
        }

        if (c) continue;
        
        cout << "-1" << nl; return;
    }

    cout << ans.size() << nl;
    
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
// problem-url: https://codeforces.com/contest/2092/problem/D
