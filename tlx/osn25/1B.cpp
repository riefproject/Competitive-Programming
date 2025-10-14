#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;
using ll = long long;
const int LIMIT = 200000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int keep = 1;
    for (int i = 0; i < k && keep < LIMIT; ++i) keep = min(keep * 2, LIMIT);

    vector<vector<pair<int,int>>> cur;
    cur.reserve(1);
    vector<pair<int,int>> init;
    init.reserve(n);

    for (int i = 0; i < n; ++i) init.emplace_back(i, 1);
    cur.pb(move(init));

    for (int i = 0; i < k; ++i) {
        vector<vector<pair<int,int>>> l, r;
        l.reserve(min((int)cur.size(), keep));
        r.reserve(min((int)cur.size(), keep));

        for (size_t j = 0; j < cur.size(); ++j) {
            const auto &rle = cur[j];
            vector<pair<int,int>> L; L.reserve(rle.size());
            vector<pair<int,int>> R; R.reserve(rle.size());

            int nl = n, nr = n;
            for (size_t ri = 0; ri < rle.size() && (nl > 0 || nr > 0); ++ri) {
                int val = rle[ri].fi;
                int len = rle[ri].se;
                ll cnt = (ll)len * 2; 

                while (cnt > 0 && (nl > 0 || nr > 0)) {
                    if (nl > 0) {
                        int take = (int)min<ll>(cnt, nl);
                        if (!L.empty() && L.back().fi == val) L.back().se += take;
                        else L.emplace_back(val, take);
                        nl -= take;
                        cnt -= take;
                    } else {
                        int take = (int)min<ll>(cnt, nr);
                        if (!R.empty() && R.back().fi == val) R.back().se += take;
                        else R.emplace_back(val, take);
                        nr -= take;
                        cnt -= take;
                    }
                }
            }

            if ((int)l.size() < keep) l.pb(move(L));
            if ((int)r.size() < keep) r.pb(move(R));

            if ((int)l.size() >= keep && (int)r.size() >= keep) break;
        }

        vector<vector<pair<int,int>>> nxt;
        nxt.reserve(min((int)l.size() + (int)r.size(), keep));
        for (size_t i = 0; i < l.size() && (int)nxt.size() < keep; ++i) nxt.pb(move(l[i]));
        for (size_t i = 0; i < r.size() && (int)nxt.size() < keep; ++i) nxt.pb(move(r[i]));

        cur.swap(nxt);
    }

    int outcnt = min((int)cur.size(), LIMIT);
    for (int i = 0; i < outcnt; ++i) {
        ll s = 0;
        for (auto &pr : cur[i]) s += a[pr.fi] * (ll)pr.se;
        cout << s << '\n';
    }
    return 0;
}