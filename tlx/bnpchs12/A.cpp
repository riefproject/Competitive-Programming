#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    long long va, da;
    int ans = 1;
    cin >> va >> da;

    for (int i = 2; i <= n; ++i) {
        long long v, d;
        cin >> v >> d;
        if (d * va < da * v) {
            ans = i;
            va = v;
            da = d;
        }
    }

    cout << ans << '\n';
    return 0;
}