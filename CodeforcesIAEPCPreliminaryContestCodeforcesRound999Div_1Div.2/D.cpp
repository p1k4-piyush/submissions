//  And when I felt like I was an old cardigan
//  Under someone's bed
//  You put me on and said I was your favorite


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;

void solve(){
	int n,m; cin >> n >> m;
	multiset<int> m1,m2;
    int t;
	for(int i = 0; i < n; i++){
		cin >> t; m1.insert(t);
	}
    for(int i = 0; i < m; i++){
        cin >> t; m2.insert(t);
    }

    while(m1.size() >= m2.size() && !m2.empty()){
        auto it = --m2.end();
        t = *it;
        auto it2 = m1.find(t);
        if (it2 == m1.end()){
            m2.insert(t/2); m2.insert((t+1)/2);
        }else{
            m1.erase(it2);
        }
        m2.erase(it);
    }



	cout << ((m2.empty() && m1.empty())?"Yes":"No") << nl;
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
// problem-url: https://codeforces.com/contest/2061/problem/D
