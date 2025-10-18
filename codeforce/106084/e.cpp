#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int INF2 = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-9;

using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
using ushort = unsigned short;
template<typename T> using vec2D = vector<vector<T>>;
template<typename T, typename U> using pr = pair<T, U>;
template<typename T, typename U> using umap = unordered_map<T, U>;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define fromv(v, n) v.begin() + n, v.end()
#define tov(v, n) v.begin(), v.begin() + n
#define atv(v, n) v.begin() + n
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define len(x) (int)(x).length()
#define lb lower_bound
#define ub upper_bound
#define endl '\n'
#define feach(var, container) for (auto &var : container)
#define debug(x) cerr << #x << " = " << (x) << endl;


void solve(){
    int n, m, k;
    if(!(cin >> n >> m >> k)) return;

    vector<pr<int, int>> slabstones(k);
    for (int i = 0; i < k; ++i) {
        cin >> slabstones[i].fi >> slabstones[i].se;
    }

    int u1, v1, u2, v2;
    cin >> u1 >> v1 >> u2 >> v2;

    auto didalem = [&](int r, int c) {
        return r >= u1 && r <= u2 && c >= v1 && c <= v2;
    };

    auto check = [&](int maxi) {
        int geser = 0;
        int bener = 0;

        for (int i = 0; i < k; ++i) {
            if (didalem(slabstones[i].fi, slabstones[i].se)) {
                if (i + 1 > maxi) {
                    return false; 
                }
                geser++;
            } else {
                if (i + 1 > maxi) {
                    bener++;
                }
            }
        }

        ll areadev = (ll)(u2 - u1 + 1) * (v2 - v1 + 1);
        ll areaout = (ll)n * m - areadev;
        ll areakos = areaout - bener;

        return geser <= areakos;
    };

    int l = 0, h = k, ans = -1;
    while(l <= h){
        int mid = l + (h - l) / 2;
        if(check(mid)){
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    
    return 0;
}