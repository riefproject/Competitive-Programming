#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> a) {
    int n = a.size();
    
    map<int, int> freq;
    for (int x : a) freq[x]++;
    
    int changes = 0;
    
    while (true) {
        int total = 0;
        for (auto& [s, cnt] : freq) total += cnt;
        
        if (total == 0) break;
        
        if (freq.count(total) && freq[total] > 0) {
            freq.erase(total);
        } else {
            changes++;
            
            auto it = freq.begin();
            if (it->second == 1) {
                freq.erase(it);
            } else {
                freq[it->first]--;
            }
        }
    }
    
    return changes;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--; 
        
        a[x] = y;
        cout << solve(a) << "\n";
    }
    
    return 0;
}