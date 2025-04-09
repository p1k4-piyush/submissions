//  Bad was the blood on the song in the cab
//  On your first trip to LA
//  You ate at my favorite spot for dinner

#include <bits/stdc++.h>
using namespace std;


#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

typedef int64_t ll;

const ll INF = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/home/piyush/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

const int N = 2e5 + 100;

struct Trie {
  static const int B = 31;
  struct node {
    node* nxt[2];
    int sz;
    node() {
      nxt[0] = nxt[1] = NULL;
      sz = 0;
    }
  }*root;
  Trie() {
    root = new node();
  }
    void insert(int val) {
    node* cur = root;
    cur -> sz++;
    for (int i = B - 1; i >= 0; i--) {
      int b = val >> i & 1;
      if (cur -> nxt[b] == NULL) cur -> nxt[b] = new node();
      cur = cur -> nxt[b];
      cur -> sz++;
    }
    // return cur;
  }

    void erase(int val) {
        node* cur = root;
        cur->sz--;
        for (int i = B - 1; i >= 0; i--) {
            int b = (val >> i) & 1;
            cur = cur->nxt[b];
            cur->sz--;
        }
    }
    int qq(int num){
        node * cur = root;

        int ans = 0;
        for(int i = B-1; i >= 0; i--){
            int b = (num >> i)&1;
            int x = 1-b;
            if(cur->nxt[x] && cur->nxt[x]->sz >0){
                ans |= (1<<i);
                cur = cur->nxt[x];
            }else{
                cur = cur->nxt[b];
            }
        }
        return ans;
    }
} t;


int n,k;
vector<int> arr;

bool check(int m) {
    Trie trie;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int best = trie.qq(arr[i]);
            if (best >= k) return true;
        }
        trie.insert(arr[i]);
        if (i >= m) {
            trie.erase(arr[i - m]);
        }
    }
    return false;
}
void solve(){
    cin >> n >> k;
    arr.assign(n,0);
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if(k == 0){
        cout << 1 << nl;
        return;
    }
    
    int lo = 1, hi = n;
    int ans = -1;
    while(hi >= lo){
        int mid = (hi+lo+1)/2;

        if(check(mid)){
            ans = mid+1;
            hi = mid-1;
        }else{
            lo = mid+1;
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2093/problem/G
