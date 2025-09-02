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
#define sz(x) x.size()
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define fi first 
#define se second 
#define forv(a) for(int i = 0; i < a; ++i)
#define rforv(a) for(int i = a-1; i >= 0; --i)
#define rep(i, a) for(int i = 0; i < a; ++i)
#define rrep(i, a) for(int i = a-1; i >= 0; --i)
#define whoosh ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================

void solve(){
    ll n; cin >> n;
    vll h(n);
    forv(n) cin >> h[i];

    ll ans = 0, cur = 0, nxt = 0;
    
    ll i = 0;
    while(i < n - 1){
        if(h[i] > h[i + 1]){
            i++;
            continue;
        }

        cur = h[i];
        for(int j = i + 1; j < n; ++j){
            if(j == n - 1){
                nxt = h[j];
                i = j;
                break;
            }
            else if (h[j] < h[j + 1]){
                continue;
            }

            nxt = h[j];
            i = j++;
            break;
        }
        ans += (nxt - cur);
    }

    cout << ans;

}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}