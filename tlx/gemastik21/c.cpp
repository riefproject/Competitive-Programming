#include <bits/stdc++.h>
using namespace std;

typedef unsigned int        uint;
typedef unsigned short      ushort;
typedef long long           ll;
typedef unsigned long long  ull;
typedef vector<ll>          vll;
typedef vector<int>         vii;
typedef pair<int, int>      pii;
typedef pair<ll, ll>        pll;

#define all(x)       x.begin(), x.end()
#define rall(x)      x.rbegin(), x.rend()
#define sortv(x)     sort(all(x))
#define rsortv(x)    sort(rall(x))
#define atv(x, n)    x.begin() + n
#define maxv(x)      (*max_element(all(x)))
#define minv(x)      (*min_element(all(x)))
#define sumv(x)      accumulate(all(x), 0LL)
#define sz(x)        x.size()
#define len(x)       x.length()
#define pb           push_back
#define ppb          pop_back
#define pf           push_front
#define ppf          pop_front
#define fi           first
#define se           second
#define forv(a)      for(size_t i = 0; i < a; ++i)
#define rforv(a)     for(size_t i = a-1; i >= 0; --i)
#define rep(i, a)    for(size_t i = 0; i < a; ++i)
#define rrep(i, a)   for(size_t i = a-1; i >= 0; --i)
#define whoosh       ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================

void solve(){
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    forv(n) cin >> a[i];
    vector<vector<ll>> adj(n + 1);
    vector<bool> visited(n + 1);

    forv(k){
        int x, y;
        cin >> x >> y;
        adj[--x].pb(--y);
        adj[y].pb(x);
    }

    auto bfs = [&](int point){
        queue<int> q;
        q.push(point);
        visited[point] = 1;

        int sum = a[point];
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto y : adj[x]){
                if(!visited[y]){
                    visited[y] = 1;
                    sum += a[y];
                    q.push(y);
                }
            }
        }
        return sum;
    };

    vector<int> cache;

    forv(n) if(!visited[i]) cache.pb(bfs(i));
    sort(rall(cache));

    int ans = 0;
    int j = 1;
    for(auto x : cache) ans += x * j++;

    cout << ans << '\n';
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}