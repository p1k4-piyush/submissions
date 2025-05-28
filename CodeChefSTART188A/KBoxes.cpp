//  Sequin smile, black lipstick
//  Sensual politics
//  When you are young, they assume you know nothing

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;
#define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif



void evermore(){
    int n,k;
    cin >> n >> k;
    vector<pair<int,int>> arr(n,{0,0});
    vector<int> idx(n,0);
    iota(idx.begin(),idx.end(),0);
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i].second;
    }
    sort(idx.begin(),idx.end(),[&](int i,int j){
        return arr[i]<arr[j];
    });
    sort(arr.begin(),arr.end());
    dbg(idx);
    vector<int> ans(n,0);
    priority_queue<int,vector<int>,greater<int>> pq;
    int sum = 0;
    for(int i = 0; i < n; i++){
        ans[idx[i]] = sum;
        pq.push(arr[i].second);
        sum += arr[i].second;
        if(pq.size()>k){
            sum -= pq.top();
            pq.pop();
        }
    }
    for(auto &i:ans){
        cout << i << " ";
    }
    
    cout << nl;
    return;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while(number_of_albums--){
        evermore();
    }
    return 0;
}


// time-limit: 1000
// problem-url: https://www.codechef.com/START188A/problems/KBOXES
