//  And I can go anywhere I want
//  Anywhere I want, just not home
//  And you can aim for my heart, go for blood
//  But you would still miss me in your bones


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()
#define int ll
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
string s;

void solve(){

	cin >> s;
    n = s.size();
    int a,b,ab,ba;
	cin >> a >> b >> ab >> ba;
    int ab1 = ab, ba1 = ba;

    vector<int> abab,baba,aba;
    int idx = 0;
    for(int i = 1; i < n+1; i++){
        if (i == n||s[i]==s[i-1]){
            int t = i-idx;
            idx = i;
            if (t == 1) continue;
            if (t&1){
                aba.push_back(t);
            }else if (s[i-1] == 'A'){
                baba.push_back(t);
            }else{
                abab.push_back(t);
            }
        }
    }
    sort(all(abab));
    sort(all(baba));
    sort(all(aba));
    for(auto &i:abab){
        while(i > 0 && ab > 0){
            ab--; i-=2;
        }
    }
    
    for(auto &i:baba){
        while(i > 0 && ba > 0){
            ba--; i-=2;
        }
    }

    for(auto &i:abab){
        while(i > 2 && ba > 0){
            ba--; i-=2;
        }
    }

    for(auto &i:baba){
        while(i > 2 && ab > 0){
            ab--; i-=2;
        }
    }
    
    for(auto &i:aba){
        while(i > 1 && ab > 0){
            i-=2; ab--;
        }
        while(i > 1 && ba > 0){
            i-=2; ba--;
        }
    }

    dbg(ab); dbg(ba);

    int a1 = 0;
    for(auto i:s){
        if (i == 'A'){
            a1++;
        }
    }

    int b1 = n-a1;
    if (a < a1-ab1-ba1+ab+ba){
        cout << "NO" << nl; return;
    }
    
    if (b < b1-ab1-ba1+ab+ba){
        cout << "NO" << nl; return;
    }

    
    


	cout << "YES" << nl;
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



// time-limit: 2000
// problem-url: https://codeforces.com/contest/2069/problem/E
