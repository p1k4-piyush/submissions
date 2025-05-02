//  I guess you never know, never know
//  And if you wanted me, you really should have showed
//  And if you never bleed, you're never gonna grow
//  And it's alright now



#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const int MOD = 1000000007;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/piyush/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;

void solve(){
	int n,m,t; cin >> n >> m;
	vector<int> arr(n*m +1);

	for(int i = 1; i < n*m+1; i++){
		cin >> arr[i];
	}

    map<int,int> mp;
    for(int i = 1; i < n*m+1; i++){
        cin >> t; mp[t] = i;
    }
    int count = 0;
    for(int i = 1; i < n*m+1; i++){
        if (mp.count(arr[i])){
            arr[i] = mp[arr[i]];
        }else{
            for(int j = i; j < n*m+1; j++){
                arr[j]=-1;
            }
            break;
        }
    }

    t = 0;
    bool is = 1;
    for(int i = 1; i < n*m+1; i++){
        if(arr[i-1]>arr[i]){
            break;
        }

        int d = arr[i]-arr[i-1]-1;
        if (!is && d!=0){
            break;
        }

        if(is){
            count+=d;
        }

        dbg(make_pair(i,count));
        if(count >= m-1){
            is = 1;
        }else if((i-1)%m > (i-1+count)%m || (i+count)%m == 0){
            is = 1;
        }else{
            is = 0;
        }

        if(is){
            t = i;
        }
    }



	cout << n*m-t << nl;
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



// time-limit: 3000
// problem-url: https://codeforces.com/contest/2059/problem/E1
