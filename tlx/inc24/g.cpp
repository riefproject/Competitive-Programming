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

int cnt;
void dfs(int u, vec2D<int>& adj, vector<bool>& visited) {
    cnt = 1;
    visited[u] = true;
    for(auto v : adj[u]){
        if(!visited[v]){
            dfs(v, adj, visited);
            cnt++;
        }
    }
}

template<typename T>
void clearVec(vector<T> &vec, T id){
    for(int i = 0; i < vec.size(); ++i)
        if(i == id) vec[i] = 1;
        else vec[i] = 0;
}

template <typename T>
void printMtx(vec2D<T> vec){
    for(int i = 1; i < vec.size(); ++i){
        for(int j = 1; j < vec[i].size(); ++j){
            cout << vec[i][j] << ' ';
        }
        cout << '\n';
    }
}

template<typename T>
void printArr(vector<T> vec){
    for(int i = 1; i < vec.size(); ++i) cout << vec[i] << ' ';
    cout << endl; 
}

void update(vec2D<int> &adj, int x, int y){
    adj[x][y] = 1;
    adj[y][x] = 0;
}

void DBG(vec2D<int> adj, vector<int> cur, vector<pair<int, int>> req){
    printMtx(adj);
    cout << "cur: ";
    printArr(cur);

    cout << "req: ";
    feach(i, req) cout << i.fi << ' ';
    cout << endl;
}

void solve(){
    int n, m; cin >> n >> m;
    vec2D<int> adj(n + 1, vector<int>(n + 1, 0));
    vec2D<bool> visited(n + 1, vector<bool>(n + 1, false));
    vector<int> cur(n + 1, 0);

    for(int i = 1; i <= m; ++i){
        int u, v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i = 1; i <= n; ++i){
        adj[i][i] = 1;
        for(int j = 1; j <= n; ++j){
            cur[i] += adj[i][j];
        }
    }

    // val, vertex        
    vector<pair<int, int>> req(n);

    for(int i = 0; i < n; ++i){
        int x; cin >> x;
        req[i] = {x, i};
    }
    
    // sort(all(req));

    DBG(adj, cur, req);

    for(int i = 1; i <= n; ++i){
       for(int j = 1; j <= n; ++j){
            if(req[i - 1].fi < cur[i]){
                if(i == j) continue;
                if(adj[i][j] == 1){
                    adj[i][j] = 0;
                    adj[j][i] = 1;
                }
            }
       }
    }
    for(int i = 0; i < n; ++i){

    }

    vector<int> temp(n + 1, 0);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            temp[i] += adj[i][j];
        }
    }
    cur = temp;

    cout << "tahap 2:\n";
    DBG(adj, cur, req);


    

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t=1;
    // cin>>t;

    while(t--) solve();
    
    return 0;
}