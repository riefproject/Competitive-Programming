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

inline bool isvowel(char c) {
    c = toupper(c);
    return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'E';
}

inline bool except(char c) {
    c = toupper(c);
    return c == 'N' || c == 'Y' || c == 'G';
}

void solve() {
    string str; cin >> str;
    int v = 0, s = 0, c = 0, n = 0, g = 0, y = 0, ng = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (isvowel(str[i])) v++;
        else if (!except(str[i])) c++;
        else if (except(str[i])) {
            if ((str[i]) == 'N') n++;
            else if ((str[i]) == 'G') g++;
            else y++;
        } else {
            ng++;
        }
    }

    // kombinasi aja kan harusnya?
    // 
    int res =

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin>>t;

    while (t--) solve();

    return 0;
}