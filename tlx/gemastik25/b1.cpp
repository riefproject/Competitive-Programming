#include <bits/stdc++.h>
using namespace std;
const int MOD = 1'000'000'007;

inline int addmod(int a, int b){ a += b; if(a >= MOD) a -= MOD; return a; }

// generate mask valid (tidak ada dua '1' berjarak <=2)
void gen_masks(int C, int M, vector<int>& masks, vector<int>& bits){
    function<void(int,int)> dfs = [&](int pos, int cur){
        if(pos >= C){
            int pc = __builtin_popcount((unsigned)cur);
            if(pc <= M) { masks.push_back(cur); bits.push_back(pc); }
            return;
        }
        // kosong
        dfs(pos+1, cur);
        // isi, jika aman
        if(pos>=1 && (cur>>(pos-1)&1)) return;
        if(pos>=2 && (cur>>(pos-2)&1)) return;
        dfs(pos+1, cur | (1<<pos));
    };
    dfs(0,0);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R,C,M,B;
    cin >> R >> C >> M >> B;
    if(B!=0){ cout << "subsoal B!=0 tidak ditangani di kode ini\n"; return 0; }

    vector<int> masks,bits;
    gen_masks(C, M, masks, bits);
    int S = masks.size();

    // precompute kompatibilitas
    vector<vector<char>> ok(S, vector<char>(S));
    for(int i=0;i<S;i++) for(int j=0;j<S;j++)
        ok[i][j] = ((masks[i] & masks[j])==0);

    auto idx = [&](int p1,int k){ return p1*(M+1)+k; };
    vector<vector<int>> cur(S, vector<int>(S*(M+1),0)), nxt(S, vector<int>(S*(M+1),0));

    int z = find(masks.begin(), masks.end(), 0) - masks.begin();
    cur[z][ idx(z,0) ] = 1;

    for(int r=0;r<R;r++){
        for(int p2=0;p2<S;p2++) fill(nxt[p2].begin(), nxt[p2].end(),0);
        for(int p2=0;p2<S;p2++) for(int p1=0;p1<S;p1++) for(int k=0;k<=M;k++){
            int ways = cur[p2][ idx(p1,k) ];
            if(!ways) continue;
            for(int nm=0;nm<S;nm++){
                if(!ok[p1][nm] || !ok[p2][nm]) continue;
                int nk = k+bits[nm];
                if(nk>M) continue;
                nxt[p1][ idx(nm,nk) ] = addmod(nxt[p1][ idx(nm,nk) ], ways);
            }
        }
        cur.swap(nxt);
    }

    int ans=0;
    for(int p2=0;p2<S;p2++) for(int p1=0;p1<S;p1++)
        ans = addmod(ans, cur[p2][ idx(p1,M) ]);
    cout << ans << "\n";
}
