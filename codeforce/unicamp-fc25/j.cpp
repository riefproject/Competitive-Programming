#include <bits/stdc++.h>
using namespace std;

typedef unsigned int        uint;
typedef unsigned short      ushort;
typedef long long           ll;
typedef unsigned long long  ull;
typedef vector<ll>          vll;
typedef vector<int>         vii;
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pll;

#define all(x)       x.begin(), x.end()
#define rall(x)      x.rbegin(), x.rend()
#define sortv(x)     sort(all(x))
#define rsortv(x)    sort(rall(x))
#define allfi(x)     all(x), [&](const pll &a, const pll &b) {return a.fi < b.fi;}
#define rallfi(x)    all(x), [&](const pll &a, const pll &b) {return a.fi > b.fi;}
#define allse(x)     all(x), [&](const pll &a, const pll &b) {return a.se < b.se;}
#define rallse(x)    all(x), [&](const pll &a, const pll &b) {return a.se > b.se;}
#define atv(x, n)    x.begin() + n
#define maxv(x)      (*max_element(all(x)))
#define minv(x)      (*min_element(all(x)))
#define sumv(x)      accumulate(all(x), 0LL)
#define sz(x)        x.size()
#define len(x)       x.length()
#define pb           push_back
#define ppb          pop_back
#define pf           push_front
#define ppf          pop_front
#define fi           first
#define se           second
#define forv(a)      for(int i = 0; i < a; ++i)
#define rforv(a)     for(int i = a-1; i >= 0; --i)
#define rep(i, a)    for(int i = 0; i < a; ++i)
#define rrep(i, a)   for(int i = a-1; i >= 0; --i)
#define whoosh       ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================

ushort minwin = 99;
vector<string> ans;
ushort nwin(vector<string> &m){
    ushort win = 0;

    vector<vector<pii>> lines = {
        {{0, 0}, {0, 1}, {0, 2}}, // row atas 
        {{1, 0}, {1, 1}, {1, 2}}, // row tengah
        {{2, 0}, {2, 1}, {2, 2}}, // row bawah
        {{0, 0}, {1, 1}, {2, 2}}, // diag atas kiri - bawah kanan
        {{0, 2}, {1, 1}, {2, 0}}  // diag atas kanan - bawah kiri
    };

    for (auto &line : lines) {
        char p;
        ushort wild = 0;
        
        forv(3){
            p = m[line[i].fi][line[i].se];
            if (p == '*') wild++;
        } 
        
        if (wild >= 2) win++;
    }
    return win;
}

void backtrack(ushort idx, ushort k, vector<string> &m){
    if (idx == 9) return;

    if (k == 0) {
        ushort win = nwin(m);
        if (win < minwin) {
            minwin = win;
            ans = m;
        }
        return;
    }

    ushort row = idx / 3;
    ushort col = idx % 3;

    char c = m[row][col];
    m[row][col] = '*';
    backtrack(idx + 1, k - 1, m);
    
    m[row][col] = c;
    if( 9 - idx + 1 >= k) backtrack(idx + 1, k, m);
}

void solve(){
    vector<string> m {"123", "456", "789"};
    ushort k; cin >> k;
    backtrack(0, k, m);

    for(auto l : ans) cout << l << endl;
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}