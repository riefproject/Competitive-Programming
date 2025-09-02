#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

ll nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * ifact[r]) % MOD) * ifact[n - r]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    init_fact();
    short n, a, b;
    cin >> n >> a >> b;
    
    ll ans = 0;
    for(int i = a; i <= b; ++i){
        ans = ((ans % MOD) + (nCr(n, i) % MOD)) % MOD;
    }
    cout << ans << '\n';
}
