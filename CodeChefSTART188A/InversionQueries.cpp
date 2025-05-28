//  I'm not your problem anymore
//  So what am I defending now?
//  You were my crown
//  Now I'm in exile, seein' you out

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

template <typename T>
class FenwickTree {
 public:
  vector<T> fenw;
  int n;
  int pw;

  FenwickTree() : n(0) {}
  FenwickTree(int n_) : n(n_) {
    fenw.resize(n);
    pw = bit_floor(unsigned(n));
  }

  void Modify(int x, T v) {
    assert(0 <= x && x <= n);
    while (x < n) {
      fenw[x] += v;
      x |= x + 1;
    }
  }

  T Query(int x) {
    assert(0 <= x && x <= n);
    T v{};
    while (x > 0) {
      v += fenw[x - 1];
      x &= x - 1;
    }
    return v;
  }

  // Returns the length of the longest prefix with sum <= c
  int MaxPrefix(T c) {
    T v{};
    int at = 0;
    for (int len = pw; len > 0; len >>= 1) {
      if (at + len <= n) {
        auto nv = v;
        nv += fenw[at + len - 1];
        if (!(c < nv)) {
          v = nv;
          at += len;
        }
      }
    }
    assert(0 <= at && at <= n);
    return at;
  }
};
// C++ program to Count Inversions in an array using merge sort


// This function merges two sorted subarrays arr[l..m] and arr[m+1..r] 
// and also counts inversions in the whole subarray arr[l..r]
int countAndMerge(vector<int>& arr, int l, int m, int r) {
  
    // Counts in two subarrays
    int n1 = m - l + 1, n2 = r - m;

    // Set up two vectors for left and right halves
    vector<int> left(n1), right(n2);
    for (int i = 0; i < n1; i++)
        left[i] = arr[i + l];
    for (int j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    // Initialize inversion count (or result) and merge two halves
    int res = 0;
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {

        // No increment in inversion count if left[] has a 
        // smaller or equal element
        if (left[i] <= right[j]) 
            arr[k++] = left[i++];
      
        // If right is smaller, then it is smaller than n1-i 
      	// elements because left[] is sorted
        else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    // Merge remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    return res;
}

// Function to count inversions in the array
int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if (l < r) {
        int m = (r + l) / 2;

        // Recursively count inversions in the left and 
        // right halves
        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);

        // Count inversions such that greater element is in 
      	// the left half and smaller in the right half
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversionCount(vector<int> &arr) {
  	int n = arr.size();
  	return countInv(arr, 0, n-1);
}

void evermore(){
    int n,q;
    cin >> n >> q;
    vector<int> arr(n,0);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        mp[arr[i]] = i;
    }
    vector<int> inv(n,0);
    FenwickTree<int> fenw(n);
    
    for(int i = 1; i <= n; i++){
        inv[i-1] = fenw.Query(n)-fenw.Query(mp[i]);
        fenw.Modify(mp[i],1);
    }
    dbg(inv);
    FenwickTree<int> fenw2(n);
    vector<int> inv2(n,0);
    for(int i = n; i >= 1; i--){
        inv2[i-1] = fenw2.Query(mp[i]);
        fenw2.Modify(mp[i],1);
    }
    dbg(inv2);
    for(int i = 1; i < n; i++){
        inv[i] += inv[i-1];
    }
    for(int i = n-2; i>=0; i--){
        inv2[i] += inv2[i+1];
    }
    int l,r;
    dbg(inv);
    dbg(inv2);
    int x = inversionCount(arr);
    while(q--){
        cin >> l >> r;
        l--; r--;
        if(l == r){
            cout << "0" << nl;continue;
        }
        cout << x-inv[l]-inv2[r] << nl;
    }
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
// problem-url: https://www.codechef.com/START188A/problems/INVQUER
