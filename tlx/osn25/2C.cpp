#include <bits/stdc++.h>
using namespace std;

using ll = long long;
template <typename T, typename U> using umap = unordered_map<T, U>;
const ll MOD = 1e9 + 7;

inline ll gcd(ll a, ll b) {
    while (b) { ll t = b; b = a % b; a = t; }
    return a;
}

unordered_map<ll, vector<ll>> divc;
unordered_map<ll, unordered_map<ll, vector<ll>>> trc;
    
vector<ll>& getdiv(ll n) {
    auto it = divc.find(n);
    if (it != divc.end()) return it->second;
    
    vector<ll>& div = divc[n];
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            div.push_back(i);
            if (i != n / i) div.push_back(n / i);
        }
    }
    return div;
}

unordered_map<ll, vector<ll>>& gettrans(ll v) {
    auto it = trc.find(v);
    if (it != trc.end()) return it->second;
    
    vector<ll>& divs = getdiv(v);
    auto& validNext = trc[v];
    
    for (ll prv : divs) {
        for (ll nxt : divs) {
            ll g = gcd(prv, nxt);
            if (prv / g * nxt == v) {
                validNext[prv].push_back(nxt);
            }
        }
    }
    
    return validNext;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    unordered_map<ll, ll> dp, ndp;
    
    for (ll d : getdiv(a[1])) dp[d] = 1;
    
    for (int i = 1; i <= n; i++) {
        ndp.clear();
        
        auto& trans = gettrans(a[i]);
        
        for (const auto& p : dp) {
            ll prv = p.first;
            ll cnt = p.second;
            
            auto it = trans.find(prv);
            if (it != trans.end()) {
                for (ll nxt : it->second) {
                    auto& ref = ndp[nxt];
                    ref = (ref + cnt) % MOD;
                }
            }
        }
        
        dp.swap(ndp);
    }
    
    ll ans = 0;
    for (const auto& p : dp) {
        ans = (ans + p.second) % MOD;
    }
    
    cout << ans << "\n";
    
    return 0;
}