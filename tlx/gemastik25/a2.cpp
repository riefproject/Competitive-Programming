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
#define endl         '\n'
#define whoosh       ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================
const ll MOD = 1e9+7;
const ll MAXN = 1 << 20;
ll fact[MAXN], ifact[MAXN];

template <typename T>
T modpow(T base, T exp, T mod) {
    T result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return result;
}


inline void init_fact() {
    fact[0] = 1;
    for (int i = 1; i <= MAXN; ++i) fact[i] = (fact[i - 1] * i) % MOD;
    ifact[MAXN] = modpow(fact[MAXN], MOD - 2, MOD);
    for (int i = MAXN; i > 0; --i) ifact[i - 1] = (ifact[i] * i) % MOD;
}

ll nCr_mod(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * ifact[r]) % MOD) * ifact[n - r]) % MOD;
}

void solve(){
    ll n, k; cin >> n >> k;
    ll r = (ll)floor(log2(k)) + 1;

    cout << r << ' ';

    ll m = pow(2, n);
    ll max_bracket = 1 << (r - 1);
    ll weaker = k - 1;
    ll comb = nCr_mod(weaker, max_bracket - 1);

    ll ans = (comb * fact[max_bracket]) % MOD;
    ans = (ans * fact[m - max_bracket]) % MOD;
    ans = (ans * modpow((ll)2, n - r + 1, MOD)) % MOD;
    cout << ans << endl;
}

int main(){
    whoosh
    init_fact();

    int T = 1;
    cin >> T;

    while (T--) solve();

    return 0;
}