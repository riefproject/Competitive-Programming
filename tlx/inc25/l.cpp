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
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int MOD = 998244353;
int n, k, m;
ll l;

vec2D<ll> kali(const vec2D<ll>& a, const vec2D<ll>& b) {
    int size = a.size();
    vec2D<ll> res(size, vector<ll>(size, 0));
    for (int i = 0; i < size; ++i) 
        for (int j = 0; j < size; ++j) 
            for (int k = 0; k < size; ++k) 
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
                
    return res;
}

vec2D<ll> poww(vec2D<ll> base, ll exp) {
    int size = base.size();
    vec2D<ll> res(size, vector<ll>(size, 0));
    for (int i = 0; i < size; ++i) {
        res[i][i] = 1; 
    }
    
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = kali(res, base);
        }
        base = kali(base, base);
        exp /= 2;
    }
    return res;
}

void solve() {
    cin >> n >> k >> m >> l;

    if (k % m == 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> s(n);
    map<int, int> init;
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
        if (s[i] % m != 0) {
            init[s[i] % m]++;
        }
    }

    if (l == 1) {
        cout << init[k] << endl;
        return;
    }

    if (k == 0) {
        cout << 0 << endl;
        return;
    }

    int msz = m - 1;
    vec2D<ll> trans(msz, vector<ll>(msz, 0));

    for (int prv = 1; prv < m; ++prv) {
        for (auto const& [val, cnt] : init) {
            int nw = (1LL * prv * val) % m;
            if (nw != 0) {
                trans[prv - 1][nw - 1] = (trans[prv - 1][nw - 1] + cnt) % MOD;
            }
        }
    }
    
    vec2D<ll> pangkatin = poww(trans, l - 1);
    ll ans = 0;

    for (auto const& [val, cnt] : init) 
        if (val != 0) 
            ans = (ans + (ll)cnt * pangkatin[val - 1][k - 1]) % MOD;

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