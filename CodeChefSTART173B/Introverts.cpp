//  The wedding was charming, if a little gauche
//  There's only so far as new money goes
//  They picked out a home and called it "Holiday House"

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
vector<int> ans;
void solve(){
	cin >> n;
	priority_queue<int> o;
    ans.assign(n,0);
    ans[0] = -1;
    ans[1] = n-2;
    o.push(n-2);
    for(int i = 2; i < n; i++){
        int t = o.top();
        o.pop();
        ans[i] = (t-1)/2;
        o.push(t/2);
        o.push((t-1)/2);
    }
    dbg(ans);
    arr.assign(n,0);
    
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
    vector<int> left(n,-1);
    stack<int> s;
    for(int i = 0; i < n; i++){
        while(!s.empty() && arr[s.top()] >= arr[i]){
            s.pop();
        }

        left[i] = (s.empty())?-1:i-s.top()-1;
        s.push(i);
    }
    vector<int> right(n,-1);
    stack<int> s2;
     for(int i = n-1; i >= 0; i--){
        while(!s2.empty() && arr[s2.top()] >= arr[i]){
            s2.pop();
        }

        right[i] = (s2.empty())?-1:s2.top()-i-1;
        s2.push(i);
    }
    vector<int> ans2(n);
    for(int i = 0; i < n; i++){
        if (left[i] == -1){
            ans2[i] = right[i];
        }else if(right[i] == -1){
            ans2[i] = left[i];
        }else{
            ans2[i] = min(right[i],left[i]);
        }
    }
    vector<int> ans3(n);
    for(int i = 0; i < n; i++){
        ans3[arr[i]-1] = ans2[i];
    }
    dbg(ans3);
    dbg(ans);
    if(ans == ans3){
        cout << "YES";
    }else{
        cout << "NO";
    }
    
	cout << nl;
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



// time-limit: 1000
// problem-url: https://www.codechef.com/START173B/problems/INTROVERTS
