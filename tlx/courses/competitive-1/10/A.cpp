#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q; cin >> q;
    priority_queue<ll> pq;
    
    while(q--){
        short s; cin >> s;
        switch(s){
            case 1: 
                ll x; cin >> x;
                pq.push(x);
                break;
            case 2:
                cout << pq.top() << '\n';
                break;
            case 3:
                pq.pop();
                break;
        }
    }
}