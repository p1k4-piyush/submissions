//  They don't me all of my cages were mental
//  So I got wasted like all my potential
//  And my words shoot to kill when I'm mad
//  I have a lot of regret about that

#include "bits/stdc++.h"
using namespace std;

typedef int64_t ll;
// #define int ll

const ll inf = ll(4e18) + 5;
const char nl = '\n';

#ifdef PIKA
#include "/Users/piyushkeshan/Documents/cpp_template_library/template/debug.cpp"
#else
#define dbg(...)
#endif

void evermore()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    map<char, map<char, int>> cnt;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < q; i++) {
        char l, r;
        cin >> l >> r;
        cnt[l][r]++;
        if (r == 'a') {
            if (l == 'b' && cnt['c']['b'] > cnt1) {
                cnt1++;
            }
            if (l == 'c' && cnt['b']['c'] > cnt2) {
                cnt2++;
            }
        }
    }

    // dbg(cnt);
    dbg(cnt1);
    dbg(cnt2);

    for (char& c : s)
        if (c == 'c') {
            if (cnt['c']['a']) {
                --cnt['c']['a'];
                c = 'a';
            } else if (cnt['c']['b']) {
                --cnt['c']['b'];
                if (cnt1 && cnt['b']['a']) {
                    --cnt1, --cnt['b']['a'];
                    c = 'a';
                } else {
                    c = 'b';
                }
            }
        } else if (c == 'b') {
            if (cnt['b']['a']) {
                --cnt['b']['a'];
                c = 'a';
            } else if (cnt2 && cnt['c']['a']) {
                --cnt2, --cnt['c']['a'];
                c = 'a';
            }
        }
    cout << s << '\n';
    return;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int number_of_albums = 1;
    cin >> number_of_albums;
    while (number_of_albums--) {
        evermore();
    }
    return 0;
}
// time-limit: 3000
