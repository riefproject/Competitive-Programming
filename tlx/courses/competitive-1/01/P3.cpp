#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    unordered_map<char, char> enc, dec; 
    unordered_set<char> used;      

    bool valid = true;
    for(int i = 0; i < n; ++i) {
        char a = s1[i], b = s2[i];
        if(enc.count(a)) {
            if(enc[a] != b) valid = false;
        } else {
            enc[a] = b;
            if(used.count(b)) valid = false;
            used.insert(b);
        }
        if(dec.count(b)) {
            if(dec[b] != a) valid = false;
        } else {
            dec[b] = a;
        }
    }

    if(!valid) {
        cout << "Pak Dengklek bingung\n";
        return 0;
    }

    string ans(n, '?');
    for(int i = 0; i < n; ++i) {
        char b = s3[i];
        if(dec.count(b)) {
            ans[i] = dec[b];
        }
    }
    cout << ans << '\n';
    return 0;
}