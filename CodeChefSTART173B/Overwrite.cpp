//  I knew you
//  Hand under my sweatshirt
//  Baby, kiss it better, I

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
int n,m;
vector<int> a;
vector<int> b;

void solve(){
	cin >> n >> m;
	a.assign(n,0);
    b.assign(m,0);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    if (m == 1){
        for (int i = 0; i < n; i++){
            cout << min(a[i],b[0]) << " ";
        }
        cout << nl; return;
    }
    
    int tt = min_element(all(b))-b.begin();
    // findMinRotation(b);
    
    vector<int> c(m,0);
    for(int i = tt; i < m; i++){
        c[i-tt]=b[i];
    }
    for(int i = 0; i < tt;i++){
        c[i+m-tt] = b[i];
    }
    int t = c[0];
    tt = -1;
    for(int i = 0; i < n-m; i++){
        if (a[i]>t){
            tt = i;
            break;
        }
    }
    if (tt == -1){
        for(int i = 0; i < n-m; i++){
            cout << a[i] << " ";
        }
        vector<int> d;
        for (int i = n-m; i < n; i++){
            d.push_back(a[i]);
        }
        dbg(d);
        dbg(c);
        if (c > d){
            for(auto i:d){
                cout << i << " ";
            }
        }else{
            for(auto i:c){
                cout << i << " ";
            }
        }
    }else{
        for(int i = 0; i < tt; i++){
            cout << a[i] << " ";
        }
        for (int i = tt; i < n-m; i++){
            cout << t << " ";
        }
        
        for(auto i:c){
            cout << i << " ";
        }

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
// problem-url: https://www.codechef.com/START173B/problems/MINOVER
