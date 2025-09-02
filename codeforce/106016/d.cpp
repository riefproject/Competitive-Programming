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
#define allfi(x)     all(x), [](const pll &a, const pll &b) {return a.fi < b.fi;}
#define rallfi(x)    all(x), [](const pll &a, const pll &b) {return a.fi > b.fi;}
#define allse(x)     all(x), [](const pll &a, const pll &b) {return a.se < b.se;}
#define rallse(x)    all(x), [](const pll &a, const pll &b) {return a.se > b.se;}
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
const int MAX_N = 10000;

vector<int> generatePrimes() {
    vector<bool> isPrime(MAX_N + 1, true);
    vector<int> primes;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX_N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX_N; j += i) isPrime[j] = false;
        }
    }

    for (int i = 2; i <= MAX_N; i++) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}
vector<int> primes = generatePrimes();

void solve(){
    ll n, k; cin >> n >> k ;
    vector<ll> v(n), ans(n);
    forv(n) cin >> v[i];

    forv(n){
        ull a = 0;
        // k = 30
        // 2, 3, 5, 7, 11, 13
        while(!(k % primes[a] == 0 && v[i] % primes[a] != 0) && a < sz(primes) -1) {
            a++;
        }
        ans[i] = primes[a] > v[i] ? -1 : primes[a];
    }
    forv(n){
        cout<<ans[i]<<'\n';
    }
}

int main(){
    whoosh

    int T = 1;

    while (T--) solve();

    return 0;
}