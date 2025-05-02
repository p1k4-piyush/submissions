//  'Cause I knew you
//  Steppin' on the last train
//  Marked me like a bloodstain, I

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
int n,q;
vector<int> arr;
vector<pair<pair<int,int>,int>> query;
vector<int> ans;

void solve(){
	cin >> n >> q;
	arr.assign(n,0);
    query.assign(q,{{0,0},0});
    ans.assign(q,0);


	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    for(int i = 0; i < q; i++){
        cin >> query[i].first.first >> query[i].first.second;
        query[i].second = i;
    }
    sort(all(query));
    
    vector<int> dp;
    int tt = 0;
    for(int i = 0; i < n; i++){
        auto it = lower_bound(all(dp),arr[i]);
        if (it == dp.end()){
            dp.push_back(arr[i]);
        }else{
            *it = arr[i];
        }
        for(tt; tt < q && query[tt].first.first <= i+1 ;tt++){
            int t = upper_bound(all(dp),query[tt].first.second) - dp.begin();
            ans[query[tt].second] = t;
        }
    }

    for(auto i:ans){
        cout << i << nl;
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
// problem-url: https://atcoder.jp/contests/abc393/tasks/abc393_f
