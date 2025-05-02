//  Out of all the wrong arms right into that dive bar
//  Something wrapped all of my past mistakes in barbed wire
//  Chains around my demons, wool to brave the seasons
//  One single thread of gold tied me to you

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

int n,k;
string s;

void solve(){
    cin >> n >> k;
    cin >> s;
    dbg(n); dbg(k);dbg(s);
    int i = 0;
    vector<int> v;
    vector<int> c;
    while(i < n){
        int cur = 1;
        while(i+1 < n && s[i]==s[i+1]){
            cur++; i++;
        }
        v.push_back(cur);
        i++;
        if(cur >= k){
            c.push_back(v.size()-1);
        }
    }
    dbg(v);
    dbg(c);
    if(c.size()>2){
        cout << "NO" << nl; return;
    }
    if(c.size()==0){
        cout << "YES" << nl; return;
    }
    if(c.size()==1){
        if(v[c[0]]>=2*k-1){
            cout << "NO" << nl; return;
        }
        for(int i = c[0]-1; i >= 0; i-=2){
            if(i == 0){
                cout << "YES" << nl; return;
            }
            if(v[i]>1){
                cout << "YES" << nl; return;
            }
            if(v[c[0]]-k+1+v[i-1] < k){
                cout << "YES" << nl; return;
            }
        }
        for(int i = c[0]+1; i < v.size(); i+=2){
            if (i == v.size()-1){
                cout << "YES" << nl; return;
            }
            if(v[i]>1){
                cout << "YES" << nl; return;
            }
            if(v[c[0]]-k+1+v[i+1] < k){
                cout << "YES" << nl; return;
            }
        }
        cout << "NO" << nl; return;
    }
    if(c.size()==2){
        if((c[1]-c[0])%2){
            if((v[c[0]]<2*k-1)&&(v[c[1]]<2*k-1)){
                cout << "YES" << nl; return;
            }
        }
        cout << "NO" << nl; return;
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


// time-limit: 1000
// problem-url: https://www.codechef.com/START182B/problems/MRC
