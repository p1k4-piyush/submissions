//  But I knew you
//  Playing hide-n-seek and
//  Giving me your weekends, I

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
int arr2[MAX_N];

void solve(){
    string s,t; cin >> s >> t;
    int n = s.size();
    int sum1 = 0, sum2 = 0;
    int c1 = 0;
    int tt = 1;
    sum1 += (s[0]=='1');
    for(int i = 1; i < n; i++){
        sum1 += (s[i]=='1');
        if(s[i] == s[i-1]){
            tt++;
        }else{
            arr[c1] = tt;
            tt = 1;
            c1++;
        }
    }
    arr[c1] = tt; c1++;

    int c2 = 0;
    tt = 1;
    sum2 += (t[0]=='1');
    for(int i = 1; i < n; i++){
        sum2 += (t[i]=='1');
        if(t[i] == t[i-1]){
            tt++;
        }else{
            arr2[c2] = tt;
            tt = 1;
            c2++;
        }
    }
    arr2[c2] = tt; c2++;
    if (sum1!=sum2){
        cout << "-1" << nl; return;
    }

    int ans = 0;
    int i = 0,j = 0;
    bool same = (s[0]==t[0]);
    for(int i = 0; i < c1; i++){
        if(same){
            if(arr[i]>arr2[j]){
                cout << "-1" << nl; return;
            }
            arr2[j]-=arr[i];
            if (arr2[j]==0){
                j++; same^=1;
            }
            // i++;
            same ^= 1;
        }else{
            arr[i+2]+=arr[i];
            // i++;
            ans++;
            same ^= 1;
        }
    }

	cout << ans <<  nl;
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
