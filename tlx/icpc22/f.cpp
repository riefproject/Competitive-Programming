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
int factor(int val){
    int rtn = 0;
    while(val % 2 == 0){
        val /= 2;
        rtn++;
    }
    return rtn;
}
void solve(){
    int n; cin >> n;
    vii a(n);
    forv(n) cin >> a[i];

    int q = a[0];
    for(int i = 1; i < n; ++i) q = gcd(q, a[i]);

    priority_queue<int> pq;
    for(int i = 0; i < n; ++i){
        pq.push(-factor(a[i] / q));
    }

    int m = n - 1;
    while(m--){
        int a = -pq.top(); pq.pop();
        int b = -pq.top(); pq.pop();
        pq.push(-(min(a, b) + 1));
    }
    int l = -pq.top();
    cout << q * (1ll << l);
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;a

    while (T--) solve();

    return 0;
}