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
#define forv(a)      for(ll i = 0; i < a; ++i)
#define rforv(a)     for(ll i = a-1; i >= 0; --i)
#define rep(i, a)    for(ll i = 0; i < a; ++i)
#define rrep(i, a)   for(ll i = a-1; i >= 0; --i)
#define whoosh       ios_base::sync_with_stdio(0);cin.tie(0);

// ===============================================================
// JANGAN LUPA COMMENT TESTCASE SEBELUM SUBMIT!!
// ===============================================================

// Hitung jumlah digit dalam sebuah angka
ll countDigits(ll num) {
    if (num == 0) return 1;
    return floor(log10(num)) + 1;
}

// Mengembalikan 10^exp % mod
ll powMod(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) // Jika exp ganjil
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp >>= 1; // exp = exp / 2
    }
    return result;
}

// Konversi integer ke array digit (dari kiri ke kanan)
vector<ll> getDigits(ll n) {
    vector<ll> digits;
    if (n == 0) return {0};
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(all(digits));
    return digits;
}

bool isInsertDivisible(ll n, ll pos, ll j, ll m) {
    vector<ll> nDigits = getDigits(n);
    vector<ll> jDigits = getDigits(j);
    
    ll remainder = 0;
    
    for (ll i = 0; i < pos; i++) {
        remainder = (remainder * 10 + nDigits[i]) % m;
    }
    
    for (ll digit : jDigits) {
        remainder = (remainder * 10 + digit) % m;
    }
    
    // Proses sisa digit n
    for (ll i = pos; i < nDigits.size(); i++) {
        remainder = (remainder * 10 + nDigits[i]) % m;
    }
    
    return remainder == 0;
}

// Fungsi untuk memeriksa keterbagian string dengan m
bool isStringDivisibleByM(const string& str, ll m) {
    ll rem = 0;
    for(char c : str) {
        rem = (rem * 10 + (c - '0')) % m;
    }
    return rem == 0;
}

void solve(){
    string n;
    ll m, k;
    cin >> n >> m >> k;
    
    ll cnt = 0;
    
    // Solusi paling sederhana dan efisien: menggunakan operasi string
    for(ll i = 0; i <= n.length(); i++) {
        for(ll j = 1; j <= k; j++) {
            string jStr = to_string(j);
            
            // Buat string hasil: bagian depan + j + bagian belakang
            string result = n.substr(0, i) + jStr + n.substr(i);
            
            if(isStringDivisibleByM(result, m)) {
                cnt++;
            }
        }
    }
    
    cout << cnt;
}
}

int main(){
    whoosh

    int T = 1;
    // cin >> T;

    while (T--) solve();

    return 0;
}