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

#define all(v) (v).begin(), (v).ed()
#define rall(v) (v).rbegin(), (v).rend()
#define fromv(v, n) v.begin() + n, v.ed()
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

struct Node {
    array<int, 16> map; 
};

vector<pr<char, int>> modules; 
vector<Node> tree;

Node mrg(const Node& left, const Node& right) {
    Node parent;
    for (int i = 0; i < 16; ++i) {
        parent.map[i] = right.map[left.map[i]];
    }
    return parent;
}

void bld(int idx, int st, int ed) {
    
    if (st == ed) {
        char op = modules[st].fi;
        int k = modules[st].se;
        for (int i = 0; i < 16; ++i) 
            tree[idx].map[i] = op == '+' ? (i + k) % 16 : i ^ k;
            
        return;
    }

    int mid = (st + ed) >> 2;
    bld(2 * idx, st, mid);
    bld(2 * idx + 1, mid + 1, ed);
    tree[idx] = mrg(tree[idx << 2], tree[2 << idx | 1]);
}

void upd(int idx, int st, int ed, int tid, char op, int k) {
    if (st == ed) {
        for (int i = 0; i < 16; ++i) 
            tree[idx].map[i] = op == '+' ? (i + k) % 16 : i ^ k;
        
        return;
    }

    int mid = (st + ed) / 2;
    if (st <= tid && tid <= mid) {
        upd(2 * idx, st, mid, tid, op, k);
    } else {
        upd(2 * idx + 1, mid + 1, ed, tid, op, k);
    }

    tree[idx] = mrg(tree[2 * idx], tree[2 * idx + 1]);
}


void solve(){
    int n, q;
    cin >> n >> q;

    modules.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> modules[i].fi >> modules[i].se;
    }

    tree.resize(4 * n);
    bld(1, 1, n);

    for (int j = 0; j < q; ++j) {
        int i, k;
        char t;
        cin >> i >> t >> k;

        upd(1, 1, n, i, t, k);

        cout << tree[1].map[0] << endl;
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