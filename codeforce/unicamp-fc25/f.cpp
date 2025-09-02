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
    double d, t, k, v; cin >> d >> t >> k >> v;
    double l; cin >> l;

    double tml = t;
    double pos = k;
    double vel = v;
    short dir = 1;

    while(tml > 1e-9){
        double col;
        if(dir == 1){
            col = (d - pos) / vel;
        } else {
            col = pos / vel;
        }

        if(col >= tml){
            pos = dir * tml * vel;
            tml = 0;
        } else {
            tml -= col;
            vel *= l;
            dir = -1;

            if(dir == -1){
                pos = d;
            } else {
                pos = 0;
            }
        }

        cout << fixed << setprecision(10) << pos;
    }


}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}