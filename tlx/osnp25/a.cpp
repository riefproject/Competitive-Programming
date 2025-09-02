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
#define forv(a)      for(size_t i = 0; i < a; ++i)
#define rforv(a)     for(size_t i = a-1; i >= 0; --i)
#define rep(i, a)    for(size_t i = 0; i < a; ++i)
#define rrep(i, a)   for(size_t i = a-1; i >= 0; --i)
#define whoosh       ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================

void solve(){
    string s; cin >> s;
    int len = sz(s);
    int ans = 0;
    bool ok = false;
    unordered_map<char, int> mp;

    for(char c : s){
        if(c == 'O' || c == 'S' || c == 'N'){
            mp[c]++;
            mp['P'] = 0;
        }
        if(c == 'P'){
            if(!ok) ok = mp['O'] && mp['S'] && mp['N'] ? true : false;
            if(ok){
                mp['P']++;
                ans = max(ans + 1, mp['O'] + mp['S'] + mp['N'] + mp['P']);
            }
        }
    }

    if(ok) cout << ans << '\n';
    else cout << -1 <<'\n';
}

int main(){
    whoosh

    int T = 1;
    cin >> T;

    while (T--) solve();

    return 0;
}