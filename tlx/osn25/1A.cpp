#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()


const ll INF = (ll)9e18;

vector<ll> dijkstra(int src, const vector<vector<pair<int,int>>>& adj) {
    int n = (int)adj.size();
    vector<ll> dist(n, INF);

    priority_queue<pair<ll,int>,  
                    vector<pair<ll,int>>, 
                    greater<pair<ll,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > d + w) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;
    vector<vector<pair<int,int>>> adj(n+1), atap(n+1);
    
    for (int i = 0; i < m; ++i) {
        int u, v, w, z;
        cin >> u >> v >> w >> z;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
        if (z == 2) {
            atap[u].pb({v, w});
            atap[v].pb({u, w});
        }
    }

    vector<ll> dist = dijkstra(1, adj);
    vector<ll> distAtapFrom = dijkstra(n, atap);
    vector<pair<ll,ll>> nodes;

    nodes.reserve(n);
    for (int u = 1; u <= n; ++u) {
        ll a = dist[u];
        ll b = (distAtapFrom[u] >= INF || a >= INF) ? INF : a + distAtapFrom[u];
        nodes.emplace_back(a, b);
    }
    sort(all(nodes)); 

    int Q;
    cin >> Q;
    vector<pair<ll,int>> q(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> q[i].fi;
        q[i].se = i;
    }
    sort(all(q));

    vector<ll> ans(Q, -1);
    ll cur = INF;
    int ptr = 0;
    for (auto &qq : q) {
        ll T = qq.fi;
        int idx = qq.se;
        while (ptr < (int)nodes.size() && nodes[ptr].fi <= T) {
            if (nodes[ptr].se < cur) cur = nodes[ptr].se;
            ++ptr;
        }
        if (cur < INF) ans[idx] = cur;
        else ans[idx] = -1;
    }

    for (int i = 0; i < Q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}