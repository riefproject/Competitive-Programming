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

int n, m;
vec2D<int> f(1001, vector<int>(1001, 0)), mx(1001, vector<int>(1001, 0));

int cari(ushort x1, ushort y1, ushort x2, ushort y2){
    return f[x2][y2] - f[x1 - 1][y2] - f[x2][y1 - 1] + f[x1 - 1][y1 - 1];
}

void query(){
    ushort r, c;
    int k;
    cin >> r >> c >> k;

    ushort d = 0;
    int pre = 0, ans = 0, cnt;
    while(k > 0){
        cnt = cari(
            (r - d > 0) ? r - d : 1,
            (c - d > 0) ? c - d : 1,
            (r + d <= n) ? r + d : n,
            (c + d <= m) ? c + d : m
        );
        if (cnt >= k + pre){
            ans += d * k;
            k = 0;
        } else {
            ans += d * (cnt - pre);
            k -= (cnt - pre);pre = cnt;
        }
        d++;
    }
    cout << ans * 2 << endl;
}


void solve(){
    cin >> n >> m;
    for(ushort i = 1; i <= n; ++i){
        for(ushort j = 1; j <= m; ++j){
            char c; cin >> c;
            mx[i][j] = c - '0';
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + mx[i][j];
        }
    }

    ushort q; cin >> q;
    while(q--)
        query();
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // int t=1;
    // cin>>t;

    // while(t--) 
        solve();
    
    return 0;
}