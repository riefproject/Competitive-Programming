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
    ushort n, k;
    if(!(cin >> n >> k)) return;
    vector<ushort> p(k, 0);

    for(int i = 0; i < n; ++i){
        ushort c; 
        if(!(cin >> c)) return;
        for(int j = 0; j < c; ++j){
            ushort x; 
            if(!(cin >> x)) return;
            p[--x]++;
        }
    }

    sort(rall(p));
    feach(x, p) cout << x << ' ';
    cout << endl;

    if (k == 1) { 
        cout << 1 << endl;
        return;
    }

    if (p[0] != p[1]){
        cout << 1 << endl;
        return;
    }

    int ans = 1;

    for(int j = 1; j < k; ++j){
        if (p[0] == p[j]) ans++;
        else break;
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