#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define atv(x) x.begin() + n
#define sortv(x) sort(all(x))
#define rsortv(x) sort(rall(x))
#define maxv(x) (*max_elements(all(x)))
#define minv(x) (*min_elements(all(x)))
#define sumv(x) accumulate(all(x), 0LL)
#define sz(X) x.size()
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define fi first 
#define se second 
#define forv(a) for(int i = 0; i < a; ++i)
#define rforv(a) for(int i = a-1; i >= 0; --i)
#define whoosh ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================

void solve(){
    ll n, m;
    cin >> n >> m;
    vector<bool> seen(m + 1, false);
    vector<bool> cut(m + 1, false);

    while(n--){
        ll x; cin >> x;
        vector<ll> st(x);
        forv(x) cin >> st[i];

        forv(x){
            if(!seen[st[i]]){
                if (i < x - 1){
                    cut[st[i]] = true;
                }
                seen[st[i]] = true;
            }
        }
    }

    for(int i = 1; i <= m; ++i) cout << (cut[i] ? 1 : 0) << " ";
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}