#include <bits/stdc++.h>
#define endl '\n'
#define fi first
#define se second
#define pb push_back
#define yes "YES"
#define no "NO "

using namespace std;


using ll = long long;
const ll inf=1e18;
using ld = long double;
using pll = pair<ll,ll>;
//test again, cuz why not



struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
typedef unordered_map<long long, long long, custom_hash> safe_map;

void solve()
{
    ll n,m,q,suma=0,sumb=0,x,del1,del2,i;
    bool flag;
    cin >> n >> m >> q;
    safe_map mapa,mapb;
    vector<ll>a(n),b(m);
    for(auto &x:a)
    {
        cin >> x;
        suma+=x;
        mapa[x]=1;
    }
    for(auto &x:b)
    {
        cin >> x;
        sumb+=x;
        mapb[x]=1;
    }
    while(q--)
    {
        cin >> x;
        flag=false;
        for(i=1;i<=sqrt(abs(x));i++)
        {
            if(x%i!=0)
            {
                continue;
            }
            del1=i;
            del2=x/i;


            flag|=mapb[sumb-del1] && mapa[suma-del2];
            flag|=mapb[sumb-del2] && mapa[suma-del1];
            del1*=-1;
            del2*=-1;
            flag|=mapb[sumb-del1] && mapa[suma-del2];
            flag|=mapb[sumb-del2] && mapa[suma-del1];

        }
        if(flag)
        {
            cout << yes << endl;
            continue;
        }
        cout << no << endl;
    }






//skibidi
}





int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t=1;
    //cin >> t;
    while(t--)
    {
        solve();
    }
}
