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

typedef struct {
    int sf, i;
    string str;
} Hint;
ll n, m; 
string check(int x, vector<Hint>& vec){
    string res = "";
    forv(n){
        if(vec[i].i == x) continue;
        if(vec[i].sf <= sz(res)){
            ll a = min(sz(vec[i].str), sz(res) - vec[i].sf + 1);
            if(res.substr(vec[i].sf - 1, a) == vec[i].str.substr(0, a))
                res += vec[i].str.substr(a, sz(vec[i].str) - a);
            else
                return "";
        } else if (vec[i].sf == sz(res) + 1 && sz(res) + sz(vec[i].str) <= m)
            res += vec[i].str;
        else
            return "";
    }

    if(sz(res) != m) return "";
    return res;
}

void solve(){
    cin >> n >> m;
    vector<Hint> vc(n);
    forv(n){
        cin >> vc[i].sf >> vc[i].str;
        vc[i].i = i;
    }

    sort(all(vc), [](const Hint &a, const Hint &b){
        if(a.sf != b.sf) return a.sf < b.sf;
        if(a.str != a.str) return a.str < b.str;
        return a.i < b.i;
    });

    set<string> ans;
    forv(n+1){
        string s = check(i, vc);
        if(s != "") ans.insert(s);
    }
    if(sz(ans) == 0) cout << -1 << '\n';
    else if(sz(ans) > 1) cout << -2 << '\n';
    else cout << *ans.begin() << '\n';
}  

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}