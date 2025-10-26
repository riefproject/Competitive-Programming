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


void solve() {
    double x;
    ll l, r;
    cin >> x >> l >> r;

    if (x < l || x > r) {
        cout << -1 << endl;
        return;
    }
    ll pbg = 1e6;
    ll pbl = round(x * pbg);

    ll fpb = __gcd(pbl, pbg);

    ll k = pbg / fpb;
    ll sum = pbl / fpb;

    cout << k << endl;

    vector<ll> ratings(k, l);
    ll diff = sum - (k * l);
    ll logis = r - l;

    for (int i = 0; i < k; ++i) {
        ll add = min(diff, logis);
        ratings[i] += add;
        diff -= add;
        if (diff == 0) {
            break;
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << ratings[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    
    return 0;
}