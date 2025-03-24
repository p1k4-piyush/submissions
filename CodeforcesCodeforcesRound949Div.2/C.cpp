//  I can see you starin', honey
//  Like he's just your understudy
//  Like you'd get your knuckles bloody for me






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

vector<int> path(int l, int r){
    vector<int> L, R;
    while (int(log2(l))>int(log2(r))){
        L.push_back(l);
        l >>= 1;
    }

    while (int(log2(l))<int(log2(r))){
        R.push_back(r);
        r >>= 1;
    }
    dbg(L);
    dbg(R);
    while (l!=r){
        L.push_back(l);
        R.push_back(r);
        l >>= 1;
        r >>= 1;
    }
    L.push_back(l);
    FOR2(i,R.size()){
        L.push_back(R[i]);
    }

    return L;
}

const int MAX_N = 1e6+100;
int arr[MAX_N];

void solve(){
	int n; cin >> n;
	vector<int> v;
    FOR(i,n){
    	cin >> arr[i];
        if (arr[i] != -1){
            v.push_back(i);
        }
	}
    if (v.size() == 0){
        FOR(i,n){
            cout << (1<<(i%2)) << " ";
        }
        cout << nl; return;
    }
    bool o = 1;
    FOR2(i,*v.begin()){
        arr[i] = (o?arr[*v.begin()]*2:arr[*v.begin()]);
        o=!o;
    }
    o = 1;
    for(int i = v.back()+1; i < n; i++){
        arr[i] = (o?arr[v.back()]*2:arr[v.back()]);
        o=!o;
    }
    FOR(i,v.size()-1){
        int l = v[i],r = v[i+1];
        vector<int> p = path(arr[l],arr[r]);
        dbg(p); 
        if (((p.size()&1) != ((r-l+1)&1)) || (p.size() > r-l+1)){
            cout << "-1" << nl; return;
        }
        
        FOR(j,p.size()){
            arr[l+j] = p[j];
        }
        o = 0;
        for(int j = l+p.size();j<r;j++){
            arr[j]= o?arr[j-1]/2:arr[j-1]*2;
            o=!o;
        }
    }
    FOR(i,n){
        cout << arr[i] << " ";
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


// time-limit: 3000
// problem-url: https://codeforces.com/contest/1981/problem/C
