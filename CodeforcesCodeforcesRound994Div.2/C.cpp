//  I never learned to read your mind
//  I couldn't turn things around
//  'Cause you never gave a warning sign
//  All this time

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
int arr[MAX_N];

void solve(){
	int n; cin >> n;
    int x,y; cin >> x >> y;
    if (n%2){
        if (x%2 == y%2 && y != n){
            if (x%2){
                FOR(i,x-1){
                    cout << i%2 << " ";
                }
                cout << "2 ";
                FOR(i,n-x){
                    cout << i%2 << " ";
                }
            }else{
                FOR(i,n-1){
                    if (i == x-1){
                        cout << "2 "; continue;
                    }
                    cout << i%2 << " ";
                }
                cout << "2";
            }
        }else{
            FOR(i,n-1){
                cout << i%2 << " ";
            }
            cout << "2";
        }
    }else{
        if(x%2 == y%2){
            if (x%2==0){
                FOR(i,n){
                    if (i == x-1){
                        cout << "2 "; continue;
                    }
                    cout << i%2 << " ";
                }
            }else{
                FOR(i,n){
                    if (i == x-1){
                        cout << "2 "; continue;
                    }
                    cout << ((i+1)%2) << " ";
                }
            }
        }else{
            FOR(i,n){
                cout << i%2 << " ";
            }
        }
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2049/problem/C
