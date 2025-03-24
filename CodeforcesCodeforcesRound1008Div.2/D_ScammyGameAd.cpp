//  To kiss in cars and downtown bard
//  Was all we needed
//  You drew stars around my scars
//  But now I'm bleedin'

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
int n;
vector<pair<pair<int,bool>,pair<int,bool>>> arr;
vector<int> par;


void solve(){

    cin >> n;
    arr.resize(n);
    char o1,o2;
    par.assign(n,0);
   

    for(int i = 0; i < n; i++){
        cin >> o1 >> arr[i].first.first >> o2 >> arr[i].second.first;

        if (o1 == '+' && o2 == '+'){
            arr[i].first.second = 0;
            arr[i].second.second = 0;
            par[i] = 1;
        }

        if (o1 == '+' && o2 == 'x'){
            arr[i].first.second = 0;
            arr[i].second.second = 1;
        }
        if (o1 == 'x' && o2 == '+'){
            arr[i].first.second = 1;
            arr[i].second.second = 0;
        }
        
        if (o1 == 'x' && o2 == 'x'){
            arr[i].first.second = 1;
            arr[i].second.second = 1;
            if (arr[i].first.first == arr[i].second.first){
                par[i] = 1;
            }
        }
    }

    ll x = 1, y = 1,ex = 0;

    for (int i = 0; i < n; i++){

        if (par[i]){

            if (arr[i].first.second == 0){
                ex += arr[i].first.first + arr[i].second.first;
            }else{
                ex += (arr[i].first.first-1)*ex;
                ex += (arr[i].first.first-1)*(x+y);
            }

        }else{
        
            if (arr[i].first.second && arr[i].second.second){
                if (arr[i].first.first > arr[i].second.first){
                    x += ex;
                }else{
                    y += ex;
                }
                ex = x*(arr[i].first.first-1)+y*(arr[i].second.first-1);

            }else if (arr[i].first.second){
                x += ex;
                ex = x*(arr[i].first.first-1)+arr[i].second.first;
            }else{
                y += ex;
                ex = y*(arr[i].second.first-1)+arr[i].first.first;
            }
            
        }
        dbg(x + y + ex);
    }

    cout << x + y + ex << nl;
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
// problem-url: https://codeforces.com/contest/2078/problem/D
