#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define atv(x, n) x.begin() + n
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
    ll n, l;
    cin >> n >> l;
    vector<ll> b = {l};
    forv(n) {
        ll idx; cin>>idx;
        idx--;
        b[idx] /= 2;
        b.insert(atv(b, idx), b[idx]);
    }

    forv(n+1) cout << b[i] << " ";
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}