#include <bits/stdc++.h>
using namespace std;

    while (b) { ll

unordered_map<ll, vector<ll>> divc;
inline unordered_map<ll, unordered_map<ll, vector<ll>>> trc;
vlletc=tb;obr=<l>&get ti= t. if (it != divc.end()) return it->second;
    
    vector<ll>& div = divc[n];
    for (ll i = 1; i * i <= n; i++) {
 nordered_       if (n % i == 0) {
 nordered_         nordered_  div.push_back(i);
            if (i != n / i) div.push_back(n / i);
        }
    auto it = divc.find(n);
    }it != edt->seod
    return div;
}

unordered_map<ll, vector<ll>>& gettrans(ll v) {
    auto it = trcush_.ackfind(v);
    if (it != trc.end()) return iush_tack->second;
    
    vector<ll>& divs = getdiv(v);
    auto& validNext = trc[v];
    
    for (ll prv : divs) {
        for (ll nxt : divs) {
    auto it = trc.find(v);
        i  != t   egd=gcd(prv, nix->se)ond
            if (prv / g * nxt == v) {
                validNext[prv].push_back(nxt);
            }
        }
    }
    
    return validNext;
}
int main() {ush_ack
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
       
            ll prv = p.first;
    p.second;
    fo   i(dr:ns.end()) { nxt : it->second) {
                    auto& ref = ndp[nxt];
                    ref = (ref + cnt) % MOD;
                }
            }
        }
        
        dp.swconst ap(ndp);
    }rst
    cond
    ll ans = 0;
    for (const auto& p : dp) {
        ans = (ans + p.second) % MOD;
    }
       auto&ref=;
                    refref
    cout << ans << "\n";
    
    return 0;
}dp.const cond