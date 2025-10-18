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

int find(int u, vector<int>& parent) {
    if (u != parent[u]) parent[u] = find(parent[u], parent);
    return parent[u];
}

void prim(int start, const vec2D<pr<int, int>>& graph, vector<int>& parent) {
    int n = sz(graph);
    vector<int> key(n, INF);
    vector<bool> inMST(n, false);
    parent.assign(n, -1);
    key[start] = 0;
    parent[start] = -1;
    priority_queue<pr<int, int>, vector<pr<int, int>>, greater<pr<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [k, u] = pq.top();
        pq.pop();
        inMST[u] = true;

        for (auto &[v, w] : graph[u]) {
            if (!inMST[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
                parent[v] = u;
            }
        }
    }
}

void kruskal(int n, const vector<tuple<int, int, int>>& edges, vector<pr<int, int>>& mst) {
    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; i++) parent[i] = i;

    function<int(int)> find = [&](int u) {
        if (u != parent[u]) parent[u] = find(parent[u]);
        return parent[u];
    };

    auto unionSets = [&](int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            } else if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            } else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    };

    vector<tuple<int, int, int>> sortedEdges = edges;
    sort(all(sortedEdges));

    mst.clear();
    for (auto &[w, u, v] : sortedEdges) {
        if (find(u) != find(v)) {
            unionSets(u, v);
            mst.push_back({u, v});
        }
    }
}

int solve(){

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    
    return 0;
}