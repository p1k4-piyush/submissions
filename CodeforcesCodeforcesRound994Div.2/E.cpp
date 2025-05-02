//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'




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
ll n;

bool ask (int l, int r, bool first) {
    if (first){
        int t = n-l+1;
        l = n-r+1;
        r = t;
    }
    cout << "? " << l << " " << r << nl; cout.flush();
    cin >> first;
    return first;
}

void solve(){
    cin >> n;
    bool a = ask(1,n/4,0);
    bool b = ask(n/4 +1,n/2,0);
    bool first = 1;
    if (a == b){
        first = 0;
    }

    bool knby2 = ask(1,n/2,first);
    ll ans = 0;
    if (knby2){
        for (int k = n/4;k>0;k/=2){
            if(!ask(1,ans+k,first)) ans += k;
        }
    }else{
        ans = n/2 -1;
        for(int k = n/4;k>0;k/=2){
            if(ask(1,ans+k,!first)) ans += k;
        }
    }
    cout << "! " << ans+1 << nl;
    cout.flush();
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
// problem-url: https://codeforces.com/contest/2049/problem/E


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2049/problem/E


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2049/problem/E


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2049/problem/E
