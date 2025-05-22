//  Stood on the cliffside
//  Screaming, "Give me a reason"
//  Your faithless love's the only hoax
//  I believe in

#include <bits/stdc++.h>
using namespace std;

typedef int64_t ll;

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA 
#include "/Users/piyushkeshan/cpp_template_library/template/debug.cpp" 
#else
#define dbg(...)
#endif


// https://takeuforward.org/data-structure/count-inversions-in-an-array/ 
int merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //Modification 1: cnt variable to count the pairs:
    int cnt = 0;

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1); //Modification 2
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }

    return cnt; // Modification 3
}

int mergeSort(vector<int> &arr, int low, int high) {
    int cnt = 0;
    if (low >= high) return cnt;
    int mid = (low + high) / 2 ;
    cnt += mergeSort(arr, low, mid);  // left half
    cnt += mergeSort(arr, mid + 1, high); // right half
    cnt += merge(arr, low, mid, high);  // merging sorted halves
    return cnt;
}

int numberOfInversions(vector<int>a, int n) {

    // Count the number of pairs:
    return mergeSort(a, 0, n - 1);
}

int n;
vector<pair<int,int>> o,e;
vector<int> arr;
void solve(){
    cin >> n;
    arr.assign(n,0);
    o.assign(0,{0,0});
    e.assign(0,{0,0});
    
    int t;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        t = arr[i];
        if (i&1){
            o.push_back({t,i}); 
        }else{
            e.push_back({t,i});
        }
    }

    int inv = numberOfInversions(arr,n);

    sort(o.begin(),o.end());
    sort(e.begin(),e.end());
    
    


    for(int i = 0; i < n; i++){
        if (i&1){
            arr[i] = o[i/2].first;
        }else{
            arr[i] = e[i/2].first;
        }
    }
    
    int inv2 = numberOfInversions(arr, n);
    if(inv%2 != inv2%2){
        swap(arr[n-1],arr[n-3]);
    }

    for(auto i:arr){
        cout << i << " ";
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


// time-limit: 2000
// problem-url: https://codeforces.com/contest/2102/problem/D
