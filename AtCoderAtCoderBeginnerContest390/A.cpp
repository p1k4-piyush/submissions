//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones

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
	int n=5;
	bool c = 1;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
        if (arr[i] == i+1){
            continue;
        }else if (arr[i] == i+2&&c){
            i++;
            cin >> arr[i];
            if (arr[i] == i){
                c = 0;continue;
            }
        }else{
            cout << "No" << nl; return;
        }
	}
    
    

	cout << ((c==1)?"No":"Yes") << nl;
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
// problem-url: https://atcoder.jp/contests/abc390/tasks/abc390_a
