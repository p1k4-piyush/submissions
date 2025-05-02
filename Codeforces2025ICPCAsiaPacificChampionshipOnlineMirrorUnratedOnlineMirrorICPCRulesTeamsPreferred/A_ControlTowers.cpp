//  Even on my worst day, did I deserve, babe
//  All the hell you gave me?
//  'Cause I loved you, swear I loved you
//  'Til my dying day

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) (x).begin(), (x).end()

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef DEBUG 
#include "/home/dbg/debug.cpp" 
#else
#define dbg(...)
#endif

const int MAX_N = 2e5+100;
int r,c;
vector<vector<int>> arr;

void solve(){
    cin >> r >> c;
    arr.assign(r,vector<int>(c,0));
    char t;
    ll ans = 0;

    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> t;
            if (t == '.') arr[i][j] = 1;
        }
    }

    vector<ll> dpi (r,0), dpj(c,0);

    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (arr[i][j]){
                dpi[i]++;
                dpj[j]++;
            }
        }
    }
    
        
    for (int i = 0; i < r; i++){
        ll t = 0;
        for(int j = 0; j < c; j++){
            if (!arr[i][j]) continue;
            ans += 2ll*t*(dpj[j]-1ll);
            t += dpj[j]-1ll;
        }

        for(int j = 0; j < c; j++){
            if (!arr[i][j]) continue;
            ans += 2ll*(dpj[j]-1ll)*(dpi[i]-1ll)*(dpi[i]-2ll);
        }

        ans += dpi[i]*(dpi[i]-1ll)*(dpi[i]-2ll)*(dpi[i]-3ll);
    }

    vector<vector<int>> arr2(c,vector<int>(r,0));
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            arr2[j][i]=arr[i][j];
        }
    }
    arr = arr2;
    swap(r,c);

    dpi.assign(r,0);
    dpj.assign(c,0);

    for(int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            if (arr[i][j]){
                dpi[i]++;
                dpj[j]++;
            }
        }
    }
    
        
    for (int i = 0; i < r; i++){
        ll t = 0;
        for(int j = 0; j < c; j++){
            if (!arr[i][j]) continue;
            ans += 2ll*t*(dpj[j]-1ll);
            t += dpj[j]-1ll;
        }

        for(int j = 0; j < c; j++){
            if (!arr[i][j]) continue;
            ans += 2ll*(dpj[j]-1ll)*(dpi[i]-1ll)*(dpi[i]-2ll);
        }

        ans += dpi[i]*(dpi[i]-1ll)*(dpi[i]-2ll)*(dpi[i]-3ll);
    }



    cout << ans << nl;
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
// problem-url: https://codeforces.com/contest/2073/problem/A
