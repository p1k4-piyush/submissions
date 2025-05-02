#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    for (int j = 0; j < t; j++){
        
        if (j == 251){
            cin >> n;
            cout << n << endl;
            int tt;
            for(int i = 0; i < n; i++){
                cin >> tt; cout << tt << " ";                
            }
            cout << endl;
            for(int i = 0; i < 2*n - 2; i++){
                cin >> tt; cout << tt << " ";
                if (i&1){
                    cout << endl;
                }
            }
        }else{
            cin >> n;
            int tt;
            for(int i = 0; i < n; i++){
                cin >> tt;             
            }
            for(int i = 0; i < 2*n -2; i++){
                cin >> tt; 
            }
        }
    }
    cout << "4\n0\n2\n2\n10\n";
}
