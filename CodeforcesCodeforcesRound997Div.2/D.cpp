//  But I knew you
//  Dancin' in your Levis
//  Drunk under a streetlight, I


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

const int MAX_N = 1e5+100;
int arr[MAX_N];
int arr2[MAX_N];


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<long long, int, custom_hash> safe_map;
void solve(){
	int n; cin >> n;
	
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    
    ll ans = ((ll)n*(ll)(n+1ll))/2ll;
    for (int i = 1 ; i < 11; i++){
        arr2[0] = n;
        for(int j = 0; j < n; j++){
            if (arr[j] <= i){
                arr2[j+1] = arr2[j]+1;
            }else{
                arr2[j+1] = arr2[j]-1;
            }
        }
        int k = 0;
        safe_map mp;
        for(int j=0; j < n; j++){
            if(arr[j] == i){
                while(k <= j){
                    mp[arr2[k++]]++;
                    dbg(arr2[k]);
                }
            }
            ans -= mp[arr2[j+1]];
        }
    }
	cout <<  ans <<  nl;
	return;
}


signed main() {
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
// problem-url: https://codeforces.com/contest/2056/problem/D

// time-limit: 2000
// problem-url: https://codeforces.com/contest/2056/problem/D
