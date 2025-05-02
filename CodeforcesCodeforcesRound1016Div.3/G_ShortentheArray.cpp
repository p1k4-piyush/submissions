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
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif

const int BITS = 31;            // Maximum bit index for 32-bit integers.
const int MAX_NODES = 3200000;  // Maximum number of trie nodes.

// Global trie data: each node has two children (for bit 0 and bit 1).
// If a pointer is -1, that child does not exist.
int trie[MAX_NODES][2];

// Each node has a counter indicating how many numbers pass through that node.
int cnt[MAX_NODES];

// 'sz' indicates the next available index for a new node.
int sz;

// Initialize the trie: reset all pointers and counters.
void initTrie() {
    memset(trie, -1, sizeof(trie));
    memset(cnt, 0, sizeof(cnt));
    sz = 1; // Root is at index 0.
}

// Insert a number into the trie.
// Updates both the trie structure and the node usage counts.
void insertNum(int num) {
    int node = 0;
    cnt[node]++; // Increase count for the root.
    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (trie[node][bit] == -1) {
            trie[node][bit] = sz++;  // Allocate a new node when needed.
        }
        node = trie[node][bit];
        cnt[node]++;  // Increment count along the path.
    }
}

// Remove a number from the trie.
// It decrements the usage counters along the number's path and
// clears pointers if the node is no longer used.
void eraseNum(int num) {
    int node = 0;
    cnt[node]--; // Decrement count for the root.
    // First, traverse the trie and decrement the counts.
    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int child = trie[node][bit];
        // If the number isn't found in the trie, return early.
        if (child == -1) {
            return;
        }
        node = child;
        cnt[node]--;
    }
    
    // Second, traverse again to disconnect any nodes that are no longer used.
    node = 0;
    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int child = trie[node][bit];
        // If this child's counter is zero, no number uses this node anymore.
        // Remove the pointer from its parent.
        if (cnt[child] == 0) {
            trie[node][bit] = -1;
            break;  // The remaining subtree is no longer reachable.
        }
        node = child;
    }
}

// Query the trie to find the maximum XOR for a given number.
// It attempts to take the path that yields a 1 in each bit position.
int maxXorQuery(int num) {
    int node = 0;
    int ans = 0;
    for (int i = BITS; i >= 0; i--) {
        int bit = (num >> i) & 1;
        int toggled = 1 - bit;
        // Check if the desired branch exists and is active.
        if (trie[node][toggled] != -1 && cnt[trie[node][toggled]] > 0) {
            ans |= (1 << i);
            node = trie[node][toggled];
        } else {
            node = trie[node][bit];
        }
    }
    return ans;
}

int n,k;
vector<int> arr;

bool check(int m) {
    initTrie();

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            int best = maxXorQuery(arr[i]);
            if (best >= k) return true;
        }
        insertNum(arr[i]);
        if (i >= m) {
            eraseNum(arr[i - m]);
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
