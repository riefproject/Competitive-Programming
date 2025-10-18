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

vector<bool> isPrime;
const int MAXN = 1e6 + 5;

void sieve(int n = MAXN) {
    isPrime.assign(n + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

void solve(){
    int x, y;
    if(!(cin >> x >> y)) return;
    if(x + 2 != y){
        cout << "N\n";
        return;
    }

    cout << (isPrime[x] && isPrime[y] ? "Y\n" : "N\n");
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve();
    int t=1;
    cin>>t;

    while(t--) solve();
    
    return 0;
}