//  Remember when I pulled up and said, "Get in the car"
//  And then canceled my plans, just in case you'd call
//  Back when I was livin' for the hope of it all
//  "Meet me behind the mall"

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif


//	https://github.com/the-tourist/algo/

#include <ext/pb_ds/assoc_container.hpp>

template <typename K, typename V, typename Comp = std::less<K>>
using ordered_map = __gnu_pbds::tree<
	K, V, Comp,
	__gnu_pbds::rb_tree_tag,
	__gnu_pbds::tree_order_statistics_node_update
>;

template <typename K, typename Comp = std::less_equal<K>>
using ordered_multiset = ordered_map<K, __gnu_pbds::null_type, Comp>;

// Supports
//  auto iterator = ordered_set().find_by_order(idx); // (0-indexed)
//  int num_strictly_smaller = ordered_set().order_of_key(key);




const ll MAX_N = 1e9+100;
ll n,m;
vector<vector<ll>> arr;

void solve(){
    cin >> n;
    m = n;
    arr.assign(n,vector<ll>(m,0));
    
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    
    for(auto &i:arr){
        sort(i.begin(),i.end());
    }
    // dbg(arr);
    vector<pair<ll,ll>> intervals;
    vector<vector<ll>> sum(n,vector<ll>(m+1,0));

    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){
            sum[i][j+1] = arr[i][j];
            sum[i][j+1] += sum[i][j];
        }
    }
    // dbg(sum);
    
    for(int i = 1; i < n; i++){
        set<ll> ss(arr[0].begin(),arr[0].end());
        ss.insert(0);
        ss.insert(MAX_N);
        for(int j = 0; j < m; j++){
            ss.insert(arr[i][j]);
        }
        vector<ll> s2;
        for(auto j:ss){
            s2.push_back(j);
        }
 
        for(int j = 0; j < s2.size()-1; j++){

            int t1 = upper_bound(arr[0].begin(),arr[0].end(),s2[j]+1)-arr[0].begin();
            int t2 = upper_bound(arr[i].begin(),arr[i].end(),s2[j]+1)-arr[i].begin();
            ll s = sum[0][t1]-sum[i][t2];
            ll d = t2-t1;

            if(s < 0 && d == 0){
                intervals.push_back({s2[j]+1,s2[j+1]});
            }else if(d > 0){
                ll ttt = (-s+d-1/d)-1;
                ttt = min(ttt,s2[j+1]);
                if (ttt <= s2[j]) continue;
                intervals.push_back({s2[j]+1,ttt});
            }else if (d < 0){
                ll ttt = (-s/d)+1;
                ttt = max(ttt,s2[j]+1);
                if (ttt > s2[j+1]) continue;
                intervals.push_back({ttt,s2[j+1]});
            }

        }

    }
    dbg(intervals);
    
    sort(intervals.begin(),intervals.end());
    ll ans=1;
    ll mx=0;
    ordered_multiset<ll> ss;
    for(int i=0;i<intervals.size();++i){
        ll x=ss.size()-ss.order_of_key(intervals[i].first)+1;
        if(x>mx){
            mx=x;
            ans=intervals[i].first;
        }
        ss.insert(intervals[i].second);
    }
    
    cout << ans << nl;
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
// problem-url: https://www.codechef.com/START182B/problems/MNSM
