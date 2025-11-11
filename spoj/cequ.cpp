
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using lll = __int128;
using ull = unsigned long long;
using uint = unsigned int;
using ushort = unsigned short;
template<typename T> using vec2D = vector<vector<T>>;
template<typename T, typename U> using pr = pair<T, U>;
template<typename T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T> using max_heap = priority_queue<T, vector<T>, less<T>>;

#define int ll
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

const int INF = 1e9;
const ll INF2 = 1e18;
const int MOD = 1e9 + 7;
const double PI = acos(-1.0);
const double EPS = 1e-9;

struct LDE {
    ll a, b, c;

    LDE(ll a, ll b, ll c) : a(a), b(b), c(c) {}

    ll gcd_ext(ll a, ll b, ll& x, ll& y) {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        ll x1, y1;
        ll d = gcd_ext(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return d;
    }

    bool adaSolusi(ll& x0, ll& y0, ll& g) {
        g = gcd_ext(llabs(a), llabs(b), x0, y0);
        if (c % g != 0) return false;

        x0 *= c / g;
        y0 *= c / g;
        if (a < 0) x0 = -x0;
        if (b < 0) y0 = -y0;
        return true;
    }

    void shift(ll& x, ll& y,
        ll a_, ll b_, ll cnt) {
        x += cnt * b_;   // x = x + cnt * (b/g)
        y -= cnt * a_;   // y = y - cnt * (a/g)
    }

    ll all_lde(ll minx, ll maxx,
        ll miny, ll maxy) {
        ll x, y, g;
        if (!adaSolusi(x, y, g)) return 0;

        ll a_ = a / g;
        ll b_ = b / g;

        ll sign_a = a_ > 0 ? 1 : -1;
        ll sign_b = b_ > 0 ? 1 : -1;

        // batasi x di [minx, maxx]
        shift(x, y, a_, b_, (minx - x) / b_);
        if (x < minx)
            shift(x, y, a_, b_, sign_b);
        if (x > maxx)
            return 0;
        ll lx1 = x;

        shift(x, y, a_, b_, (maxx - x) / b_);
        if (x > maxx)
            shift(x, y, a_, b_, -sign_b);
        ll rx1 = x;

        // batasi y di [miny, maxy]
        shift(x, y, a_, b_, -(miny - y) / a_);
        if (y < miny)
            shift(x, y, a_, b_, -sign_a);
        if (y > maxy)
            return 0;
        ll lx2 = x;

        shift(x, y, a_, b_, -(maxy - y) / a_);
        if (y > maxy)
            shift(x, y, a_, b_, sign_a);
        ll rx2 = x;

        if (lx2 > rx2) swap(lx2, rx2);
        ll lx = max(lx1, lx2);
        ll rx = min(rx1, rx2);

        if (lx > rx) return 0;
        // banyak solusi = (jarak / step) + 1
        return (rx - lx) / llabs(b_) + 1;
    }
};


void solve() {
    ll a, b, c, x1, x2, y1, y2;
    cin >> a >> b >> c >> x1 >> x2 >> y1 >> y2;
    LDE lde(a, b, c);
    cout << (lde.all_lde(x1, x2, y1, y2)) << endl;
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1, i = 1;
    // cin >> t;

    while (t--) {
        // cout << "Case " << i++ << ": ";
        solve();
    }

    return 0;
}