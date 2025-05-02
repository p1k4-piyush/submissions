//  I can see you starin', honey
//  Like he's just your understudy
//  Like you'd get your knuckles bloody for me

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
    string s,s2; cin >> s >> s2;
    string o = "sick";
    string t = "fine";
    if (s == o){
        if(s2 == o){
            cout << "1";
        }else{
            cout << "2";
        }
    }else{
        if (s2 == o){
            cout << "3";
        }else{
            cout << "4";
        }
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
// problem-url: https://atcoder.jp/contests/abc393/tasks/abc393_a
