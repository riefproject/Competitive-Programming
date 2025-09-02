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
    pll p = {0, 0};
    //     T   U   B   S
    // x  +1   0   0  -1
    // y   0  +1  -1   0

    /* 
        TC 3: TUUB
    */

    int n; cin>>n;
    ll i = 1;
    while(n > 0){
        ll mv = i % 4;
        if(n - i < 0) i = n;

        switch (mv) {
        case 1: p.fi += i; break;
        case 2: p.se += i; break;
        case 3: p.fi -= i; break;
        default: p.se -= i; break;
        }

        n -= i;
        i++;
    }

    cout << p.fi << " " << p.se << "\n";
}

int main(){
    whoosh

    int T = 1;
    cin >> T;

    while (T--) solve();

    return 0;
}