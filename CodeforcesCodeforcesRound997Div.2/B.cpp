//  And you can aim for my heart, go for blood
//  And you would still miss me in your bones
//  And I still talk to you
//  And when you can't sleep at night (you hear my stolen lullabies)

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
int arr[MAX_N];

void solve(){
	int n; cin >> n;
    char t;

	for(int i = 0; i < n; i++){
        int tt = 0;
        for(int j = 0; j < n; j++){
            cin >> t;
            if (i == j){
                continue;
            }else if (i > j){
                tt += (t=='1');
            }else{
                tt += (t=='0');
            }
        }
        arr[tt]=i+1;
	}

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
	cout << nl;
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



// time-limit: 1500
// problem-url: https://codeforces.com/contest/2056/problem/B
