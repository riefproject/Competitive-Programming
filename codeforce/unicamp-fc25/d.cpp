#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(x) (x.begin(), x.end())
#define rall(x) (x.rbegin(), x.rend())
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
    struct P {
        int x, y;
    }P[4];

    forv(4) cin >> P[i].x >> P[i].y;

    ll sisi[4];
    forv(4) {
        sisi[i] = pow(P[i].x - P[(i+1)%4].x, 2) + 
                  pow(P[i].y - P[(i+1)%4].y, 2);
    }
    
    bool ok = true;
    forv(4) if(sisi[i] != sisi[(i+1)%4]) {
        ok = false;
        cout << "NAO";
        return;
    }

    ll diag[2];
    forv(2) {
        diag[i] = pow(P[i].x - P[i+2].x, 2) + 
                  pow(P[i].y - P[i+2].y, 2);
    }

    cout << (ok && diag[0] == diag[1] ? "SIM" : "NAO");
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}