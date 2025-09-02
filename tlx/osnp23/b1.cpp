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

void solve(){
    ll n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n);
    
    forv(n) cin >> a[i];
    sortv(a);
    if(k == 0 && a[n-1] <= m) {cout<<0; return;}
    ll cur = m + k;
    ll ans = 0;
    forv(n){
        if(a[i] <= cur) continue;
        cur = a[i] + k;
        ans++;
    }

    cout<<ans;
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}