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

int N, M;
vector<vector<pair<int, int>>> adj;

void solve() {
    cin >> N >> M;
    adj.resize(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<vector<ll>> dist(2, vector<ll>(N + 1, INF));
    min_heap<pair<ll, int>> pq;

    dist[0][1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [current_cost, u_raw] = pq.top();
        pq.pop();

        int u = u_raw % (N + 1);
        int layer = u_raw / (N + 1);

        if (current_cost > dist[layer][u]) {
            continue;
        }

        if (layer == 0 && u == 2) {
            if (dist[0][2] < dist[1][2]) {
                dist[1][2] = dist[0][2];
                // Masuk ke Lapisan 1 dengan node 2 + (N+1)
                pq.push({dist[1][2], 2 + (N + 1)});
            }
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;
            ll cost = (layer == 0) ? weight : floor(weight / 2.0);

            if (dist[layer][u] + cost < dist[layer][v]) {
                dist[layer][v] = dist[layer][u] + cost;
                pq.push({dist[layer][v], v + layer * (N + 1)});
            }
        }
    }

    cout << dist[1][3] << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    
    return 0;
}