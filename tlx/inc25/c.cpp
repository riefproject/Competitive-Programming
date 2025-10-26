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

bool isMonoton(const vector<lll>& arr) {
    if (arr.size() <= 1) return true;
    bool inc = true, dec = true;

    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] > arr[i + 1]) inc = false;
        if (arr[i] < arr[i + 1]) dec = false;
    }
    return inc || dec;
}

bool isConst(const vector<lll>& arr) {
    if (arr.size() <= 1) return true;
    for (size_t i = 0; i < arr.size() - 1; ++i) {
        if (arr[i] != arr[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<lll> y(n);
    set<lll> dist;
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        y[i] = x;
        dist.insert(y[i]);
    }

    if (n <= 1) {
        cout << 0 << endl;
        return;
    }

    if (dist.size() == 2) {
        int ubah = 0;
        for (int i = 0; i < n - 1; ++i) 
            if (y[i] != y[i + 1]) 
                ubah++;

        if (ubah > 1) {
            cout << n - 1 << endl;
            return;
        }
    }

    if (isMonoton(y)) {
        bool gaOk = true;
        for (size_t i = 0; i < y.size() - 1; ++i) {
            if (y[i] != y[i + 1]) {
                gaOk = false;
                break;
            }
        }
        if (gaOk) cout << 0 << endl; 
        else cout << 1 << endl;          
        return;
    }

    vector<lll> cur = y;
    for (int deg = 0; deg < n; ++deg) {
        if (isMonoton(cur)) {
            if (deg == 0) 
                cout << (isConst(cur) ? 0 : 1) << endl;
            else cout << deg << endl;
            return;
        }

        vector<lll> nxt;
        for (size_t i = 0; i < cur.size() - 1; ++i) 
            nxt.pb(cur[i + 1] - cur[i]);
        cur = nxt;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    
    return 0;
}