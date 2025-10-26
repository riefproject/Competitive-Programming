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


const int MAXN = 200005;
vector<pr<int, int>> adj[MAXN];
ll d1[MAXN], d2[MAXN];
int N, S1, S2;

void bfs(int st, ll dist[]) {
    for (int i = 1; i <= N; ++i) dist[i] = -1;
    queue<int> q;
    dist[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto& e : adj[u]) {
            int v = e.fi; int w = e.se;
            if (dist[v] == -1) {
                dist[v] = dist[u] + w;
                q.push(v);
            }
        }
    }
}

struct Point {
    ll d1, d2;
    int id; 
};

vector<ll> bitcnt, bitsum;
int bitsz;

void update(int idx, ll val_d2) {
    for (; idx <= bitsz; idx += idx & -idx) {
        bitcnt[idx]++;
        bitsum[idx] += val_d2;
    }
}

pr<ll, ll> query(int idx) {
    ll count = 0, sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        count += bitcnt[idx];
        sum += bitsum[idx];
    }
    return {count, sum};
}


void solve(){
    cin >> N >> S1 >> S2;
    for (int i = 0; i < N - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }

    bfs(S1, d1);
    bfs(S2, d2);

    vector<Point> points(N);
    vector<ll> y_coords; 
    for (int i = 0; i < N; ++i) {
        points[i] = {d1[i + 1], d2[i + 1], i};
        y_coords.pb(points[i].d2);
    }
    
    sort(all(y_coords));
    y_coords.erase(unique(all(y_coords)), y_coords.end());
    
    auto yId = [&](ll val) {
        return lower_bound(all(y_coords), val) - y_coords.begin() + 1;
    };
    
    bitsz = y_coords.size();
    bitcnt.assign(bitsz + 1, 0);
    bitsum.assign(bitsz + 1, 0);

    sort(all(points), [](const Point& a, const Point& b) {
        if (a.d1 != b.d1) return a.d1 < b.d1;
        return a.d2 < b.d2;
    });

    ll ans = 0;
    ll sum = 0;

    for (int i = 0; i < N; ++i) {
        ll d1 = points[i].d1;
        ll d2 = points[i].d2;
        int yi = yId(d2);

        ans += (ll)i * d1 - sum;

        pr<ll, ll> le = query(yi);
        ans += le.se;

        pr<ll, ll> proc = query(bitsz);
        ll gcnt = proc.fi - le.fi;
        ans += gcnt * d2;
        
        ll kurangi = 0;
        pr<ll, ll> numpang = query(yId(d1));
        kurangi += numpang.se;
        kurangi += (le.fi - numpang.fi) * d1;
        ans -= kurangi;


        update(yi, d2);
        sum += d1;
    }
    
    ll sum_diag = 0;
    for (int i = 1; i <= N; ++i) {
        sum_diag += max(d1[i], d2[i]);
    }

    cout << (ans * 2 - sum_diag) / 2 << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t=1;

    while(t--) solve();
    return 0;
}