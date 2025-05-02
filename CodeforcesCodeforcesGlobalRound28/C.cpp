
//  Rebekah rode up on the afternoon train, it was sunny
//  Her saltbox house on the coast took her mind off St. Louis

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define FOR(i,n) for (ll i = 0; i < n; ++i)
#define FOR2(i,n) for (ll i = n-1; i >= 0 ; --i)

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 1e6+100;

void solve(){
	     
	string s;
    cin >> s;
    int n = s.size();
    int t2 = -1;
    FOR(i,n){
        if (t2 == -1 && s[i]=='0'){
            t2 = i;
            break;
        }
    }
    if (t2 == -1){
        cout << "1 1 1 " << n << nl; return;
    }
    int mr=-1,ml=-1;
    set<int> s2;
    FOR(i,t2){
        if (s[i]=='1'){
            s2.insert(i);
        }    
    }
    
    int tt = 0;

    while(s2.size() > 1 && tt <= n-t2-1){
        bool found = 0;
        for(auto i:s2){
            if (s[i+tt]!=s[t2+tt]){
                found = 1; break;
            }
        }
        if (found){
            vector<int> tttt;
            for(auto i:s2){
                if (s[i+tt]==s[t2+tt]){
                    tttt.push_back(i);
                }
            }
            for(auto i:tttt){
                s2.erase(i);
            }
        }
        tt++;
    }
    
    ml = *s2.begin();
    mr = ml+n-t2-1;
    cout << "1 " << n << " " <<  ml+1 << " " << mr+1 << nl;

	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2048/problem/C
