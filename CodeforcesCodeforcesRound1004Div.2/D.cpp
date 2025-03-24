//  And you can aim for my heart, go for blood
//  And you would still miss me in your bones
//  And I still talk to you
//  And when you can't sleep at night (you hear my stolen lullabies)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
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
	cin >> n;
    int t;
    map<int,int> mp;
	for(int i = 0; i < n; i++){
		cin >> t;
        mp[t] = i+1;
	}
    if (mp.size() == n){
        cout << "? " << mp[1] << " " << mp[n] << nl;
        cout.flush();
        cin >> t;
        if (t > n-1){
            cout << "! B" << nl; cout.flush();
            return;
        }else if (t < n-1){
            cout << "! A" << nl; cout.flush();
            return;
        }
        cout << "? " << mp[n] << " " << mp[1] << nl;
        cout.flush();
        int tt; cin >> tt;
        if (tt == 0 || tt!=t){
            cout << "! A" << nl; cout.flush(); return;
        }else{
            cout << "! B" << nl; cout.flush(); return;
        }
    }else{
        int t = -1;
        for (int i = 1; i <= n; i++){
            if (mp.find(i)==mp.end()){
                t = i; break;
            }
        }
        int tt = (t==1)?2:1;
        cout << "? " << t << " " << tt << nl; cout.flush();
        cin >> t;
        if(t == 0){
            cout << "! A" << nl; cout.flush(); return;
        }else{
            cout << "! B" << nl; cout.flush(); return;
        }
    }



	cout << nl;
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
// problem-url: https://codeforces.com/contest/2067/problem/D
