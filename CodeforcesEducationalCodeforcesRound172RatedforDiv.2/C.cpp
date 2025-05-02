//  We gather here, we line up, weepin' in a sunlit room
//  And if I'm on fire, you'll be made of ashes tooi


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
bool arr[MAX_N];

void solve(){
	int n,k; cin >> n >> k;
    char c;	
    vector<int> v;
    int sum = 0;
    FOR(i,n){
    	cin >> c;
        arr[i] = c-'0';
	}
    FOR2(i,n){
        if (i == 0){
            continue;
        }
        if (arr[i]){
            sum++;
        }else{
            sum--;
        }
        if (sum > 0){
            v.push_back(sum);
        }

    }
    sort(v.begin(),v.end()); 
    int ans = 0;
    while(k > 0 && !v.empty()){
        k-= v.back();
        v.pop_back();
        ans++;
    }
    	

    cout << ((k<=0)?ans+1:-1) << nl;
	return;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	unsigned int t = 1;
	cin >> t;
    int t2 = 0;
	while(t--){
        solve();    
    }
	return 0;
}



// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/2042/C
